/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_uns_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:17:05 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/19 12:17:06 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr_uns(unsigned int n, int *num)
{
	unsigned int i;

	if (n >= 10)
	{
		ft_putnbr_uns(n / 10, num);
		i = n % 10 + '0';
		ft_putchar((char)i, num);
	}
	else
	{
		i = n + '0';
		ft_putchar((char)i, num);
	}
}

static void	printinversnbr_uns(int *i, t_list *t, int *num)
{
	int t1;

	t1 = 0;
	if (!t->period)
		while (*i < t->width && (*i)++)
			t->zero && !t->minus ? ft_putchar('0', num) : ft_putchar(' ', num);
	else
	{
		while ((t->width - t->precision) > t1++)
			ft_putchar(' ', num);
		while (!(t->minus) && (*i)++ < t->precision)
			ft_putchar('0', num);
	}
}

void		printnbr_uns(unsigned int n, t_list *t, int *num)
{
	int				i;
	int				prec;
	unsigned int	n1;

	n1 = n;
	i = (n1 == 0);
	while (n1 > 0 && ++i)
		n1 /= 10;
	prec = t->precision;
	t->precision < i ? (t->precision = i) : t->precision;
	if (t->period || t->width)
		while (t->minus && i < t->precision && i++)
			ft_putchar('0', num);
	!t->minus ? printinversnbr_uns(&i, t, num) : 0;
	if (!n && t->period && !prec)
		t->width ? ft_putchar(' ', num) : 0;
	else
		ft_putnbr_uns(n, &(*num));
	t->minus ? printinversnbr_uns(&i, t, num) : 0;
}
