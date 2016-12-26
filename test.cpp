/*
 * File Name: test.cpp
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: 2016/12/26 12:07:08
 */

#include "dynlib.h"

int main(int argc, char *argv[])
{
    yatl::DynLib lib("libfoo");
    bool res = lib.load();
    assert(res == true);
    typedef void *func(void);
    func *bar = (func *)lib.getSymbol("bar");
    assert(bar != NULL);
    bar();
    lib.unload();
    return 0;
}
