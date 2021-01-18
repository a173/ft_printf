/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:00:12 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/15 20:00:13 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print(t_list *temp, va_list arg, int *num)
{
	if (temp->type == 'd' || temp->type == 'i')
		printnbr(va_arg(arg, int), temp, num);
	else if (temp->type == 'c')
		printchar(va_arg(arg, int), temp, num);
	else if (temp->type == 's')
		printstr(va_arg(arg, char*), temp, num);
	else if (temp->type == 'x' || temp->type == 'X')
		printnbr_hex(va_arg(arg, unsigned int), temp, num);
	else if (temp->type == 'u')
		printnbr_uns(va_arg(arg, unsigned int), temp, num);
	else if (temp->type == 'p')
		printpointer_hex(va_arg(arg, long), temp, num);
	else if (temp->type == '%')
		printpercent(temp, num);
	free(temp);
}

static int	ft_parser(const char **str, va_list arg, int *num)
{
	t_list *t;

	(*str)++;
	t = ft_lstnew();
	while (is_flags(t, **str) && write_flag(t, **str))
		(*str)++;
	if (ft_isdigit(**str))
		t->width = ft_atoi(*str);
	else if (**str == '*' && (t->width = va_arg(arg, int)))
		(*str)++;
	while (ft_isdigit(**str) || (is_flags(t, **str) && write_flag(t, **str)))
		(*str)++;
	if (**str == '.' && (*str)++ && (t->period = 1))
	{
		if (ft_isdigit(**str))
			t->precision = ft_atoi(*str);
		else if (**str == '*' && (*str)++)
			t->precision = va_arg(arg, int);
		while (ft_isdigit(**str))
			(*str)++;
	}
	is_type(**str) ? t->type = **str : 0;
	is_type(**str) ? (*str)++ : 0;
	ft_print(t, arg, num);
	return (*num);
}

int			ft_printf(const char *str, ...)
{
	va_list	arg;
	int		num;

	num = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
			ft_parser(&str, arg, &num);
		else
		{
			ft_putchar(*str, &num);
			str++;
		}
	}
	va_end(arg);
	return (num);
}
