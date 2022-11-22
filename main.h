#ifndef _MAIN_H
#define _MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct flags - struct containing flags
 * @t: flag for data type
 * @f: assocated function
 *
 */
typedef struct call
{
	char t;
	int (*f)(char *, va_list, int);
} call_t;



int _printf(const char *format, ...);
int handle_printf(const char *format, int i, va_list list, char buffer[], int width, int precision, int size);
#endif
