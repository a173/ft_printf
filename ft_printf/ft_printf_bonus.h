/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:11:29 by acaryn            #+#    #+#             */
/*   Updated: 2020/11/15 20:24:54 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t				ft_strlen(const char *str);
int					ft_isdigit(int c);
int					ft_atoi(const char *a);
void				ft_putchar(char c, int *num);
int					is_type(char c);
void				ft_putstr(char *s, int n, int *num);

typedef struct		s_list
{
	int				octo;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				width;
	int				precision;
	int				period;
	char			type;
}					t_list;
t_list				*ft_lstnew(void);
int					is_flags(t_list *list, char c);
int					write_flag(t_list *list, char c);
void				printchar(char c, t_list *temp, int *num);
void				printstr(char *s, t_list *temp, int *num);
void				printnbr(int n, t_list *temp, int *num);
void				printnbr_uns(unsigned int n, t_list *temp, int *num);
void				printnbr_hex(unsigned int n, t_list *temp, int *num);
void				printpointer_hex(long n, t_list *temp, int *num);
void				printpercent(t_list *temp, int *num);
int					ft_printf(const char *str, ...);

#endif
