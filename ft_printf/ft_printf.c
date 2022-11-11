#include <unistd.h>
#include <stdarg.h>

int g_var = 0;

void put_str(char *str)
{
	if (str == NULL)
		g_var += write(1,&"(null)",6);
	else
	{
		while (*str)
			g_var += write(1,str++,1);
	}
}

void put_nbr(long num)
{
	if (num < 0)
	{
		num *= -1;
		g_var += write(1,&"-",1);
	}
	if (num >= 10)
		put_nbr(num / 10);
	g_var += write(1,&"0123456789"[num % 10],1);
}

void put_hex(unsigned num)
{
	if (num >= 16)
		put_hex(num / 16);
	g_var += write(1,&"0123456789abcdef"[num % 16],1);
}

int ft_printf(char *format, ...)
{
	va_list ap;
	va_start(ap, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd' && (format += 2))
			put_nbr(va_arg(ap, int));
		else if (*format == '%' && *(format + 1) == 's' &&  (format += 2))
			put_str(va_arg(ap, char *));
		else if (*format == '%' && *(format + 1) == 'x' &&  (format += 2))
			put_hex(va_arg(ap, int));
		else
			g_var += write(1,format++,1);
	}
	va_end(ap);
	return (g_var);
}