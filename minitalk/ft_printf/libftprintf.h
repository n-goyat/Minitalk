/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:28:16 by ngoyat            #+#    #+#             */
/*   Updated: 2024/04/08 14:25:53 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h> // for variadic functions
# include <stdlib.h> // for malloc
# include <unistd.h> // standard library for write

int			ft_printf(const char *s, ...);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putpct(void);
long long	ft_check_edge(long long n, long long base, int isupper);
long long	ft_printnum(unsigned long n, unsigned long base, int isupper);
int			ft_putptr(void *n);

#endif