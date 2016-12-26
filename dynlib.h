/*
 * File Name: dynlib.h
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: 2016/12/26 12:02:29
 */

#ifndef _DYNLIB_H
#define _DYNLIB_H

#include <string>

namespace yatl {

class DynLib
{
public:
    DynLib(const std::string &filename);
    ~DynLib();
    bool load();
    void unload();
    void *getSymbol(const char *sym) const throw();
    const std::string &filename() const;

private:
    std::string filename_;
    void *handle_;
}; // class DynLib

} // namespace yatl

#endif
