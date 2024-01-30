#include "main.h"

/**
 * _printf - Acts like the printf function in the standard input and output
 * @format: Takes a string that needs to be printed
 * @...: A varidic function that takes integers, strings, characters etc
 * Return:  chara_points
 */

int _printf(const char *format, ...)
{
	va_list list_1;
	char *chara_points = NULL
		;
	va_start(list_1, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case 'c':
					chara_points = va_arg(list_1, char *);
					write(1, chara_points, 1);
					break;
				case 's':
					chara_points = va_arg(list_1, char *);
					write(1, chara_points, strlen(chara_points));
					break;
				case '%':
					write(1, "%", 1);
					break;
				default:
					write(1, "%", 1);
					write(1, format + 1, 1);
					break;
			}
			format += 2;
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}

	va_end(list_1);
	return (0);
}
