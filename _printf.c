#include "main.h"

/**
 * _printf - Custom implementation of printf function ,
 * with limited format specifiers.
 * @format: The format string containing format specifiers.
 * Return: The number of characters printed.
 */






int _printf(const char *format, ...)
{
	va_list args;
	char *s;
	char c;
	int i;
	int size = 0;
	char specifier;

	va_start(args, format);

	if (format == NULL)
		return (0);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
			if (args)
			{ 
				switch (*format)
				{
					case 's':
					s = va_arg(args, char *);
					size += printString(s);
					break;
					case 'c':
					c = va_arg(args, int);
					_putchar(c);
					break;
					case 'd':
					case 'i':
					i = va_arg(args, int);
					size += print_Integer(i);
					break;
				}
			}
		}
		else
		{
			_putchar(*format);
		}

		if (specifier != *format)
			size++;
		format++;
	}
	va_end(args);
	return (size);
}


/**
 * printString - Print a string character by character.
 * @s: The input string to print.
 * Return: the size of the sring
 */

int printString(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		return (1 + printString(s + 1));
	}
	return (0);
}

/**
 * print_Integer - Print an integer to the standard output.
 * @num: The integer to print.
 * Return: the size of the sring
 */


int print_Integer(int num)
{
	int i = 0;
	int numSize = 0;
	int size = 0;
	int *buffer;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		size++;
		return (size);
	}

	numSize = getIntSize(num);
	buffer = malloc(sizeof(int) * numSize);

	if (buffer == NULL)
		return (0);

	while (i < numSize)
	{
		buffer[i] = num % 10;
		num /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		_putchar(buffer[i] + '0');
		size++;
	}
	free(buffer);
	return (size);
}


/**
 * getIntSize - Get the number of digits in an integer.
 * @num: The input integer.
 * Return: The number of digits in the integer.
 */


int getIntSize(int num)
{
	if (num == 0)
		return (0);
	if (num < 10)
		return (1);

	return (1 + getIntSize(num / 10));

}

/**
 * _putchar - Write a character to the standard output.
 * @c: The character to write.
 * Return: On success, returns 1; on failure, returns -1.
 */
int _putchar(char c) { return (write(1, &c, 1)); }
