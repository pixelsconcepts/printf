#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int my_putchar(char c);
void print_char(va_list list_args, int *length);
void print_string(va_list list_args, int *length);
void print_percent(int *length);
void print_decimal(va_list list_args, int *length);


#endif
