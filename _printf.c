#include "main.h"





/**
 * handleSpecifier - Handle the following conversion specifiers: s,c,i,d...
 * @c: specifier
 * @args: variadic arguments
 * Return: the length of the argument
 */


int handleSpecifier(char c, va_list args)
{
	int size = 0;

	switch (c)
	{
		case 'c':
		{
			_putchar(va_arg(args, int));
			size++;
			break;
		}
		case 's':
		{
			size = printString(va_arg(args, char *));
			break;
		}
		case  'd':
		case  'i':
		{
			size = print_integer(va_arg(args, int));
			break;
		}
		case '%':
			_putchar('%');
			size++;
			break;
	}
	return (size);
}



/**
 * _printf - Custom implementation of printf function ,
 * with limited format specifiers.
 * @format: The format string containing format specifiers.
 * Return: The number of characters printed.
 */



int _printf(const char *format, ...)
{
	va_list args;

	int i = 0;
	int size = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			size++;
		}
		else if (format[i] == '%')
		{
			size += handleSpecifier(format[i + 1], args);
			i++;
		}
	i++;
	}
	va_end(args);
	return (size);
}
