#include <stdarg.h>
#include "main.h"

/**
 * print_char - Prints character with my_putchar
 *
 * @list_args: arguments from the _printf function
 *
 * @length: Keep count of the number of characters printed
 */

void print_char(va_list list_args, int *length)
{
	char c = va_arg(list_args, int);

	my_putchar(c);
	(*length)++;
}

/**
 * print_string - Prints a string of characters with my_putchar
 *
 * @list_args: arguments from the _printf function
 *
 * @length: Keep count of the number of characters printed
 */

void print_string(va_list list_args, int *length)
{
	const char *s = va_arg(list_args, const char *);

	while (*s != '\0')
	{
		my_putchar(*s);
		s++;
		(*length)++;
	}
}

/**
 * print_percent - Prints percent with my_putchar
 *
 * @length: Keep count of the number of characters printed
 */

void print_percent(int *length)
{
	my_putchar('%');
	(*length)++;
}

/**
 * print_decimal - Prints a decimal or integers with my_putchar
 *
 * @list_args: arguments from the _printf function
 *
 * @length: Keep count of the number of characters printed
 */

void print_decimal(va_list list_args, int *length)
{
	int dec = va_arg(list_args, int);
	int reversed_number = 0;

	if (dec == 0)
	{
		my_putchar('0');
		(*length)++;
		return;
	}

	if (dec < 0)
	{
		my_putchar('-');
		dec = -dec;
		(*length)++;
	}

	while (dec > 0)
	{
		reversed_number = reversed_number * 10 + dec % 10;
		dec /= 10;
	}

	while (reversed_number > 0)
	{
		my_putchar(reversed_number % 10 + '0');
		reversed_number /= 10;
		(*length)++;
	}
}
