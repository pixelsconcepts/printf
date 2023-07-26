#include <stdarg.h>
#include "main.h"
/**
 * _printf - function that that works like the stdio printf
 * @format: a character string
 * @...: elipses to show more variables
 * Return: Always 0
 */

int _printf(const char *format, ...)
{
	int length = 0;
	va_list list_args;

	va_start(list_args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				print_percent(&length);
			}
			else if (*format == 'c')
			{
				print_char(list_args, &length);
			}
			else if (*format == 's')
			{
				print_string(list_args, &length);
			}
			else if (*format == 'd' || *format == 'i')
			{
				print_decimal(list_args, &length);
			}
			else
			{
				print_xtra(*format, &length);
			}
		}
		else
		{
			my_putchar(*format);
			length++;
		}
		format++;
	}
	va_end(list_args);
	return (length);
}
