/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   services_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:19:45 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/19 12:19:47 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_list	*ft_lstnew(void)
{
	t_list *temp;

	if ((temp = (t_list*)malloc(sizeof(t_list))))
	{
		temp->octo = 0;
		temp->zero = 0;
		temp->plus = 0;
		temp->minus = 0;
		temp->space = 0;
		temp->width = 0;
		temp->precision = 0;
		temp->period = 0;
		temp->type = 0;
	}
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int		ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int		ft_atoi(const char *a)
{
	int i;
	int net;
	int num;

	i = 0;
	net = 0;
	num = 0;
	while (a[i] && ((a[i] > 8 && a[i] < 14) || a[i] == 32))
		i++;
	if (a[i] == '-')
	{
		net++;
		i++;
	}
	else if (a[i] == '+')
		i++;
	while (a[i] && (a[i] > 47 && a[i] < 58))
	{
		num = num * 10 + a[i] - '0';
		i++;
	}
	if (net > 0)
		num = -num;
	return (num);
}

void	ft_putchar(char c, int *num)
{
	write(1, &c, 1);
	(*num)++;
}
