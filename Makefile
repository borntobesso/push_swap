# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sojung <sojung@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 17:08:37 by sojung            #+#    #+#              #
#    Updated: 2022/01/18 14:38:17 by sojung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

SRCS = push_swap.c ft_ps.c ft_r.c ft_rr.c ft_init.c arg_utils.c utils.c \
error_case.c mov_utils.c pivot_utils.c ft_action.c little_sort.c big_sort.c 

BSRCS = checker.c ft_ps_checker.c ft_r_checker.c ft_rr_checker.c ft_init.c \
error_case.c arg_utils.c utils.c mov_utils.c pivot_utils.c ft_action.c \
little_sort.c big_sort.c checker_init.c checker_split.c checker_utils.c\
ft_ps.c ft_r.c ft_rr.c checker_list.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

HEADER = ./

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -o $@ -I $(HEADER) -c $<

bonus : $(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $^

clean :
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BNAME)

re : fclean all
