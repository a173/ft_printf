/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:13:02 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/19 12:59:57 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n, int *num)
{
	int i;

	if (n >= 10)
	{
		ft_putnbr((n / 10), num);
		i = n % 10 + '0';
		ft_putchar((char)i, num);
	}
	else
	{
		i = n + '0';
		ft_putchar((char)i, num);
	}
}

static void	printispec(int *n, int *i, t_list *t, int *num)
{
	t->space && !t->plus && *n > -1 ? ft_putchar(' ', num) : 0;
	if (*n < 0)
		ft_putchar('-', num);
	else if (t->plus)
		ft_putchar('+', num);
	while ((!t->period && !t->minus && t->zero && t->width - (*n < 0) > (*i)++)
		|| (t->period && (t->precision + t->space + (t->minus &&
			*n < 0) + t->plus - ((t->plus || t->space) && *n < 0)) >= (*i)++))
		ft_putchar('0', &(*num));
}

static void	printinversnbr(int *n, int *i, t_list *t, int *num)
{
	int j;
	int prec;

	j = 0;
	prec = t->precision;
	t->precision < *i ? (t->precision = *i) : t->precision;
	(t->plus || t->space) && *n > -1 ? (*i)++ : 0;
	t->minus && *n < 0 ? (*i)++ : 0;
	t->period ? (*i)++ : 0;
	while ((t->period && !t->minus && t->width - t->precision - (*n < 0) > j++)
		|| (!t->period &&
			!t->minus && !t->zero && t->width - (*n < 0) > (*i)++))
		prec < 0 ? ft_putchar('0', &(*num)) : ft_putchar(' ', &(*num));
	printispec(n, i, t, num);
	if (*n == -2147483648)
		ft_putstr("2147483648", 10, num);
	else if (!*n && t->period && !prec)
		t->width ? ft_putchar(' ', num) : 0;
	else
		ft_putnbr(*n < 0 ? *n = -*n : *n, num);
}

void		printnbr(int n, t_list *t, int *num)
{
	int i;
	int n1;

	n1 = n;
	i = (n1 == 0);
	while ((n1 > 0 || n1 < 0) && ++i)
		n1 /= 10;
	t->width < 0 ? t->minus = 1 : 0;
	t->width < 0 ? t->width = -t->width : 0;
	printinversnbr(&n, &i, t, num);
	while ((t->period && t->minus && (t->width + t->period) >= i++)
		|| (!t->period && t->minus && t->width > i++))
		ft_putchar(' ', num);
}
