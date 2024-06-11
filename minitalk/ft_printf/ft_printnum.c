/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:43:51 by ngoyat            #+#    #+#             */
/*   Updated: 2024/04/08 13:22:34 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	ft_printnum(unsigned long n, unsigned long base, int isupper)
{
	int		count;
	char	*symbols;

	count = 0;
	if (isupper == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < base)
		return (ft_putchar(symbols[n]));
	else
	{
		count += ft_printnum(n / base, base, isupper);
		if (count < 0)
			return (-1);
		count += ft_printnum(n % base, base, isupper);
		if (count < 0)
			return (-1);
	}
	return (count);
}

long long	ft_check_edge(long long n, long long base, int isupper)
{
	long long	count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		if (count < 0)
			return (-1);
		return (ft_printnum(-n, base, isupper) + 1);
	}
	return (ft_printnum(n, base, isupper));
}

int	ft_putptr(void *n)
{
	int				count;
	unsigned long	long_numba;

	long_numba = (unsigned long)n;
	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	if (long_numba < 0)
	{
		long_numba = -long_numba;
	}
	count += ft_printnum(long_numba, 16, 0);
	if (count < 0)
		return (-1);
	return (count);
}
