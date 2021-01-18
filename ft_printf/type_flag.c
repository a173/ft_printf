/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:25:13 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/19 12:25:14 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flags(t_list *list, char c)
{
	char *flags;

	if (list->zero == 0)
		flags = "#-+ 0";
	else
		flags = "#-+ ";
	while (*flags)
	{
		if (c == *flags)
			return (1);
		flags++;
	}
	return (0);
}

int		write_flag(t_list *list, char c)
{
	if (c == '#')
		list->octo = 1;
	if (c == '0')
		list->zero = 1;
	if (c == '+')
		list->plus = 1;
	if (c == '-')
		list->minus = 1;
	if (c == ' ')
		list->space = 1;
	return (1);
}

int		is_type(char c)
{
	char *type;

	type = "cspdiuxX%";
	while (*type)
	{
		if (c == *type)
			return (1);
		type++;
	}
	return (0);
}
