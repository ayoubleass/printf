#include "main.h"

int print_Binary(unsigned int num) {
	int size = 0;
	int i;
	int max_digits;
	int *bits;

	if (num == 0)
	{
		_putchar('0');
		size++;
        	return (size);
	}

	max_digits = sizeof(num) * 8;
	bits = malloc(max_digits * sizeof(int));

	if (bits == NULL)
	{
		return (-1);
	}
	i = 0;
    	
	while (num > 0)
	{
        	bits[i] = num % 2;
	        num /= 2;
		i++;
	}

	for (i--; i >= 0; i--)
	{
		_putchar(bits[i] + '0');
		size++;
	}
	free(bits);
	return size;
}
