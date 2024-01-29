#include "main.h"
/**
 * _printf -acts like the printf function in the standard input and output
 * @format: takes a string that needs to be printed
 * @...: a varidic function that takes integers, strings, characters etc
 * Return: chara_points
 */
int _printf(const char *format, ...)
{
	int chara_points = 0;

	va_list list_1;

	va_start(list_1, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (*format != '\0')
	{
		if (*format != '%')
			write(1, format, 1), chara_points++;
		else
		{
			format++;
			if (*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
				{
					char alpha = va_arg(list_1, int);

					write(1, &alpha, 1), chara_points++;
					break;
				}
				case 's':
				{
					char *strings = va_arg(list_1, char*);

					while (*strings)
						write(1, strings++, 1), chara_points++;
					break;
				}
				case '%':
					write(1, format, 1), chara_points++;
					break;
			}
		}
		format++;
	}
	va_end(list_1);
	return (chara_points);
}
