#include "main.h"

/**
 * _printf - produces an output according to a format
 * @format: char string to print
 *
 * Return: num of chars printed to stdio
 */

int _printf(const char *format, ...)
{
	int print_count;
	int count;
	va_list print_list;

	if (format == NULL)
		return (-1);

	va_start(print_list, format);

	print_count = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			count = write(1, format, 1);
			print_count += count;
		}

		else
		{
			format++;
			if (*format == '%')
			{
				count = write(1,format, 1);
				print_count += count;
			}
			if (*format == 'c')
			{
				char ch = va_arg(print_list, int);
				count = write(1, &ch, 1);
				print_count += count;
			}
			if (*format == 's')
			{
				char *str = va_arg(print_list, char*);
				int len;

				len = 0;
				while (*str != '\0')
				{
					count = write(1, str, 1);
					len++;
					str++;
				}
				print_count += len;
			}
		}
		format++;
	}
	va_end(print_list);

	return (print_count);
}
