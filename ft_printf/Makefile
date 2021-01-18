# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaryn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 11:24:21 by acaryn            #+#    #+#              #
#    Updated: 2020/11/19 13:18:10 by acaryn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c type_flag.c services.c printnbr.c printnbr_uns.c printnbr_hex.c print_char_str.c

BONUS = ft_printf_bonus.c type_flag_bonus.c services_bonus.c printnbr_bonus.c printnbr_uns_bonus.c printnbr_hex_bonus.c print_char_bonus.c
OBJDIR = obj/
OBJDIRBONUS = objbonus/
OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
OBJSBONUS = $(addprefix $(OBJDIRBONUS), $(BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJDIRBONUS) $(OBJSBONUS) $(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJS) $(OBJSBONUS)
	ranlib $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIRBONUS):
	mkdir $(OBJDIRBONUS)

$(OBJDIR)%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(OBJDIRBONUS)%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OBJDIRBONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
