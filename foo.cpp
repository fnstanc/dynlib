/*
 * File Name: foo.cpp
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: 2016/12/26 16:13:51
 */

#include <cstdio>
#include "foo.h"

void bar()
{
    printf("%s %p", __FUNCTION__, &bar);
}
