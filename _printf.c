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
		if (*format == '%' && *format != '\0')
		{
			format++;
			if (*format == '%')
			{
				my_putchar('%');
				length++;
			}
			else if (*format == 'c')
			{
				int c = va_arg(list_args, int);

				my_putchar(c);
				length++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(list_args, char*);

				while (*s != '\0')
				{
					my_putchar(*s);
					s++;
					length++;
				}

			}
		}
		else
		{
			my_putchar(*format);
			length++;
			format++;
		}
	}
	va_end(list_args);
	return (length);
}
