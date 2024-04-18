/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:34:58 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/18 12:24:27 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
#include "../libft.h"

static int ft_putchar_fd_printf(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

static int ft_putstr_fd_printf(int fd, char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}

static int ft_putnbr_fd_printf(int fd, int nbr)
{
	char *str = "0123456789";
	int count;
	count = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		count++;
		nbr *= -1;
	}
	if(nbr / 10 > 0)
		count += ft_putnbr_fd_printf(fd, nbr / 10);
	count += ft_putchar_fd_printf(fd, str[nbr % 10]);
	return (count);
}

static int ft_parse_format(int fd, const char *format, int *i, va_list args)
{
	int	count;

	count = 0;
	(*i)++;
	if (format[*i] == 'c')
		count += ft_putchar_fd_printf(fd, va_arg(args, int));
	else if (format[*i] == 's')
		count += ft_putstr_fd_printf(fd, va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_putnbr_fd_printf(fd, va_arg(args, int));
	else
		count += ft_putstr_fd_printf(fd, "Invalid format");
	return (count);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if(format[i] != '%')
			count += ft_putchar_fd_printf(fd, format[i]);
		else
			count += ft_parse_format(fd, format, &i, args);
		i++;
		
	}
	va_end(args);
	return (count);
}
