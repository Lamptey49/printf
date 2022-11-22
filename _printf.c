#include <stdarg.h>
#include "main.h"

void print_buffer(char buffer[], int *buffered_ind);

/**
 * _printf - printf funtion
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int i;
	int printed = 0;
	int printed_chars = 0;
	int flags, width, prec, size, buffered_ind = 0;

	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffered_ind++] = format[i];
			if (buffered_ind == BUFF_SIZE)
				print_buffer(buffer, &buffered_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buffered_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			prec = get_precision(fomat, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer, flags, width, prec, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buffered_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - prints the contents of the buffer if it exist
 * @buffer: array of chars
 * @buffered_ind: index at which the next char represents
 */
void print_buffer(char buffer[], int *buffered_ind)
{
	if (*buffered_ind > 0)
		write(1, &buffer[0], *buffered_ind);
	*buffered_ind = 0;
}
