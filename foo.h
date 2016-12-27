/*
 * File Name: foo.h
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: 2016/12/26 16:13:49
 */

#ifndef _FOO_H
#define _FOO_H

#if defined(_WIN32) || defined(_WIN64)
#define YATL_API extern "C" __declspec(dllexport)
#else
#define YATL_API extern "C"
#endif

YATL_API void bar();

#endif
