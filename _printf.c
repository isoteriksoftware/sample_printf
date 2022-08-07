#include "main.h"

int resolve_specifiers(va_list args, int i)
{
	while (format[i] == '%')
	{
		switch (format[i + 1])
		{
			case 'c':
				printed += print_char(args);
				i += 2;
				break;
			case '%':
				_putchar('%');
				printed++;
				i += 2;
				break;
			case 's':
				printed += print_string(args);
				i += 2;
				break;
			default:
				_putchar(format[i]);
				_putchar(format[i + 1]);
				i += 2;
		}
	}
	
	return (i);
}

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int printed = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		i = resolve_specifiers(args, i);

		if (format[i])
		{
			_putchar(format[i]);
			printed++;
		}

		i++;
	}
	va_end(args);

	return (printed);
}
