#ifndef PRINTF_H
#define PRINTF_H
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int getIntSize(int num);
int _printf(const char *format, ...);
int printString(char *s);
int print_Integer(int num);
int print_Binary(unsigned int num);

#endif
