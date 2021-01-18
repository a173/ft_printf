/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:16:56 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/19 13:17:46 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex(long n, char c, int *num)
{
	int i;

	if (n > 15)
	{
		ft_putnbr_hex(n / 16, c, num);
		if (n % 16 > 9)
			if (c == 'X')
				i = ((n % 16) - 10) + 65;
			else
				i = ((n % 16) - 10) + 97;
		else
			i = (n % 16) + '0';
		ft_putchar((char)i, num);
	}
	else
	{
		if (n > 9)
			if (c == 'X')
				i = (n - 10) + 65;
			else
				i = (n - 10) + 97;
		else
			i = n + '0';
		ft_putchar((char)i, num);
	}
}

static void	printinversnbr_hex(int *i, t_list *t, int *num)
{
	int t1;

	t1 = 0;
	if (!t->period)
		while (*i < t->width && (*i)++)
			(t->zero && !t->minus) ?
				ft_putchar('0', &(*num)) : ft_putchar(' ', num);
	else
	{
		while ((t->width - t->precision - (t->octo ? 2 : 0)) > t1++)
			ft_putchar(' ', num);
		!t->minus && !t->zero && (!t->period || (t->period &&
			t->precision < t->width)) && t->octo ? ft_putstr("0", 1, num) : 0;
		!t->minus && !t->zero && (!t->period || (t->period &&
			t->precision < t->width)) && t->octo ?
				ft_putstr(&t->type, 1, num) : 0;
		while (!(t->minus) && (*i)++ < t->precision)
			ft_putchar('0', num);
	}
}

static void	printispec_hex(int *i, t_list *t, int *num)
{
	(t->minus || t->zero || (t->period && t->precision >= t->width))
		&& t->octo ? ft_putstr("0", 1, num) : 0;
	(t->minus || t->zero || (t->period && t->precision >= t->width))
		&& t->octo ? ft_putstr(&t->type, 1, num) : 0;
	while (t->period && t->minus && *i < t->precision && (*i)++)
		ft_putchar('0', num);
}

void		printnbr_hex(unsigned int n, t_list *t, int *num)
{
	int				i;
	int				prec;
	unsigned int	n1;

	n1 = n;
	i = (n1 == 0);
	while (n1 > 0 && ++i)
		n1 /= 16;
	prec = t->precision;
	t->precision < i ? (t->precision = i) : t->precision;
	t->octo && !t->period ? i += 2 : 0;
	printispec_hex(&i, t, num);
	!t->minus ? printinversnbr_hex(&i, t, num) : 0;
	!t->minus && !t->zero && !t->period && t->octo ? ft_putstr("0", 1, num) : 0;
	!t->minus && !t->zero && !t->period && t->octo ?
		ft_putstr(&t->type, 1, num) : 0;
	if (!n && t->period && !prec)
		t->width ? ft_putchar(' ', num) : 0;
	else
		ft_putnbr_hex(n, t->type, num);
	t->minus ? printinversnbr_hex(&i, t, num) : 0;
}

void		printpointer_hex(long n, t_list *t, int *num)
{
	int		i;
	long	n1;

	n1 = n;
	i = (n1 == 0);
	while (n1 > 0 && ++i)
		n1 /= 16;
	i += 2;
	t->minus ? ft_putstr("0x", 2, num) : 0;
	if (!t->minus && t->width)
		while (i++ < t->width + (t->period && !t->precision))
			t->zero ? ft_putchar('0', num) : ft_putchar(' ', num);
	!t->minus ? ft_putstr("0x", 2, num) : 0;
	if (!t->minus && t->period && t->precision > t->width)
		while (i++ <= t->precision + t->width + (n == 0))
			ft_putchar('0', num);
	t->period && t->precision ? ft_putnbr_hex(n, t->type, num) : 0;
	!t->period ? ft_putnbr_hex(n, t->type, num) : 0;
	if (t->minus && t->width)
		while (i++ < t->width)
			ft_putchar(' ', num);
}
