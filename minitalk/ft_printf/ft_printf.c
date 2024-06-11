/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:30:29 by ngoyat            #+#    #+#             */
/*   Updated: 2024/04/08 13:22:05 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	format_spec(char s, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (s == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (s == 'p')
		count += ft_putptr(va_arg(ap, void *));
	else if (s == 'd' || s == 'i')
		count += ft_check_edge((va_arg(ap, int)), 10, 0);
	else if (s == 'u')
		count += ft_check_edge(va_arg(ap, unsigned int), 10, 0);
	else if (s == 'x')
		count += ft_check_edge((va_arg(ap, unsigned int)), 16, 0);
	else if (s == 'X')
		count += ft_check_edge((va_arg(ap, unsigned int)), 16, 1);
	else if (s == '%')
		count += ft_putpct();
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, s);
	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != '%')
			count += write(1, &s[i], 1);
		else if (s[i] == '%')
		{
			count += format_spec(s[i + 1], ap);
			i++;
		}
		i++;
		if (count < 0)
			return (-1);
	}
	va_end(ap);
	return (count);
}
