/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:04:41 by ngoyat            #+#    #+#             */
/*   Updated: 2024/04/15 18:40:21 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;
	int	error;
	int	i;

	count = 0;
	error = 0;
	if (!str)
		return (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (str && str[i])
		{
			error += ft_putchar(str[i]);
			count++;
			if (error < count)
				return (-1);
			i++;
		}
	}
	return (count);
}

int	ft_putpct(void)
{
	int	count;

	count = write(1, "%", 1);
	return (count);
}
