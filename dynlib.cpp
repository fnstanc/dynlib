/*
 * File Name: dynlib.cpp
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: 2016/12/26 12:02:47
 */

#include "dynlib.h"
#include <cstdio>
#include <cassert>


#if defined(__linux__)
#include <dlfcn.h>
#error no impliment yet
#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define DYNLIB_LOAD(a) (void *)LoadLibraryEx(a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH)
#define DYNLIB_GETSYM(a, b) (void *)GetProcAddress((HMODULE)(a), b)
#define DYNLIB_UNLOAD(a) !FreeLibrary((HMODULE)(a))
#define LIB_EXT ".dll"
#endif


namespace yatl {

DynLib::DynLib(const std::string &name) :
    name_(name),
    handle_(NULL)
{
    assert(name_.empty() == false);
}

DynLib::~DynLib()
{
    unload();
}

bool DynLib::load()
{
    assert(handle_ == NULL);
    printf("Loading library %s\n", name_.c_str());
    std::string file = name_;
    if (file.find(LIB_EXT) == std::string::npos) {
        file.append(LIB_EXT);
    }
    handle_ = DYNLIB_LOAD(file.c_str());
    return NULL != handle_;
}

void DynLib::unload()
{
    if (handle_) {
        printf("Unloading library %s\n", name_.c_str());
        DYNLIB_UNLOAD(handle_);
        handle_ = NULL;
    }
}

void *DynLib::getSymbol(const char *sym) const throw()
{
    assert(sym != NULL);
    assert(handle_ != NULL);
    return DYNLIB_GETSYM(handle_, sym);
}

const std::string &DynLib::name() const
{
    return name_;
}

} // namespace yatl