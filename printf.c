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
				case 'd':
				case 'i':
				{
					int num = va_arg(list_1, int);

					char buffer[12];

					int length = sprintf(buffer, "%d", num);

					write(1, buffer, length), chara_points += length;
					break;
				}
				case 'u':
				{
					unsigned int un_num = va_arg(list_1, unsigned int);

					char buffer[12];

					unsigned int un_length = sprintf(buffer, "%u", un_num);

					write(1, buffer, un_length), chara_points += un_length;
					break;
				}
				case 'o':
				{
					unsigned int unoct_int = va_arg(list_1, unsigned int);

					char buffer[12];

					unsigned int unoct_length = sprintf(buffer, "%o", unoct_int);

					write(1, buffer, unoct_length), chara_points += un_length;
					break;
				}
				case 'x':
				{
					unsigned  int hex_int = va_arg(list_1, unsigned int);

					char buffer[12];

					unsigned  int hex_length = sprintf(buffer, "%x", hex_int);

					write(1, buffer, hex_length), chara_points += hex_length;
					break;
				}
				case 'X':
				{
					unsigned int hex_int2 = va_arg(list_1, unsigned int);

					char buffer[12];

					unsigned int hex_length2 = sprintf(buffer, "%X", hex_int);

					write(1, buffer, hex_length2), chara_points += hex_length;
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
