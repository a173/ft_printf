/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:24:17 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/19 12:24:18 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(char c, t_list *t, int *num)
{
	int i;

	i = 1;
	if (!t->minus && t->width)
		while (i++ < t->width)
			t->zero ? ft_putchar('0', num) : ft_putchar(' ', num);
	ft_putchar(c, &(*num));
	if (t->minus && t->width)
		while (i++ < t->width)
			ft_putchar(' ', &(*num));
}

void	ft_putstr(char *s, int n, int *num)
{
	int i;

	i = -1;
	if (!s)
		return ;
	while (++i < n)
		ft_putchar(s[i], &(*num));
}

void	printstr(char *s, t_list *t, int *num)
{
	int i;
	int n;

	!s ? s = "(null)\0" : 0;
	n = ft_strlen(s);
	t->width < 0 ? t->minus = 1 : 0;
	t->width < 0 ? t->width = -t->width : 0;
	t->period && t->precision > -1 && n > t->precision ? n = t->precision : 0;
	i = n;
	if (!t->minus)
		while (i++ < t->width)
			t->zero ? ft_putchar('0', &(*num)) : ft_putchar(' ', &(*num));
	ft_putstr(s, n, &(*num));
	if (t->minus)
		while (i++ < t->width)
			ft_putchar(' ', &(*num));
}

void	printpercent(t_list *t, int *num)
{
	int i;

	i = 1;
	if (!t->minus && t->width)
		while (i++ < t->width)
			t->zero ? ft_putchar('0', num) : ft_putchar(' ', num);
	ft_putchar(t->type, &(*num));
	if (t->minus && t->width)
		while (i++ < t->width)
			ft_putchar(' ', num);
}
