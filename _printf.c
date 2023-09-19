#include "main.h"







int _printf(char *str, ...)
{
	va_list args;
	char specifier;
	char *s;
	char c;
	int i;
	int size = 0;

	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str >= 'a' && *str <= 'z')
			{
				specifier = *str;
			}

			switch (specifier)
			{
				case 's':
				s = va_arg(args, char *);
				printString(s);
				break;
				case 'c':
				c = va_arg(args, int);
				_putchar(c);
				break;
				case 'd':
				case 'i':
				i = va_arg(args, int);
				print_Integer(i);
				break;
			}
		}

		if (*str != specifier)
		{
			_putchar(*str);
		}
		size++;
		str++;
	}
	va_end(args);
	return (size);
}



void printString(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		printString(s + 1);
	}
}



void print_Integer(int num)
{
	int i = 0;
	int numSize = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return;
	}

	numSize = getIntSize(num);

	if (numSize == 1)
	{
		_putchar(num + '0');
	}
	else
	{
		int *buffer = malloc(sizeof(int) * numSize);
	
		if (buffer != NULL)
		{
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
			}
			free(buffer);
		}
	}
}



int getIntSize(int num)
{
	if (num == 0)
		return (0);
	if (num < 10)
		return (1);

	return (1 + getIntSize(num / 10));
}

int _putchar(char c) { return (write(1, &c, 1)); }
