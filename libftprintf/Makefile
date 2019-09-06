# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 18:33:21 by tmatthew          #+#    #+#              #
#    Updated: 2018/10/09 23:09:53 by tmatthew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DEBUG =

ifeq "$(TEST)" "FULL"
	DEBUG = -g -fsanitize=address -fsanitize=undefined
else
	DEBUG =
endif
ifdef LEAKS
        DEBUG = -g
endif

LIBFT = libft
FT_PRINTF = srcs
CC = gcc

export CC
export DEBUG

.DEFAULT_GOAL := all
all: $(LIBFT) $(FT_PRINTF)

#test: $(TEST)

.PHONY: $(LIBFT) $(FT_PRINTF) $(TEST) all

$(LIBFT):
	@$(MAKE) -C libft 2>&1;

$(FT_PRINTF):
	@$(MAKE) -C srcs;

clean:
	@$(MAKE) clean -C libft;
	@$(MAKE) clean -C srcs;

fclean:
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C srcs;
	@rm -rf libftprintf.a

re: fclean all
