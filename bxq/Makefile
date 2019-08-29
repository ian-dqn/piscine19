# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 09:29:42 by yocapell          #+#    #+#              #
#    Updated: 2019/08/28 22:12:59 by yocapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libbsq.a

SRCS = check_case check_input malloc_free open_read

CFILES = $(patsubst %, ./srcs/%.c, $(SRCS))
OBJS = $(patsubst %, ./srcs/%.o, $(SRCS))

HEADER = includes

%.o: %.c
			gcc -Wall -Wextra -Werror -I$(HEADER) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			/bin/rm -f $(OBJS)

fclean:		clean
				/bin/rm -f $(NAME)

re:	fclean all
