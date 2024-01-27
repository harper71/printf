#include "main.h"
/**
 * _printf -acts like the printf function in the standard input and output
 * @format: takes a string that needs to be printed
 * @...: a varidic function that takes integers, strings, characters etc
 * Return: chara_points
 */
int _printf(const char *format, ...)
{
	va_list list_1;

	int chara_points = 0;

	va_start(list_1, format);

	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
			chara_points++;
		else
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				char alpha = va_arg(list_1, int);

				write(1, &alpha, 1);
				chara_points++;
			else if (*format == 's')
				char *strings = va_arg(list_1, char*);

				int string_len = 0;

				while (strings[string_len] != '\0')
					string_len++;
				write(1, strings, string_len);

				chara_points = string_len;
			else if (*format == '%')
				write(1, format, 1);
				chara_points++;
		format++;
	}
	va_end(list_1);
	return (chara_points);
}
