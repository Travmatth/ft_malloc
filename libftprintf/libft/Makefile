# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 20:05:48 by tmatthew          #+#    #+#              #
#    Updated: 2019/04/26 15:27:11 by tmatthew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

CFLAGS	+= -I.
CFLAGS	+= -Wall -Wextra -Werror -Wpedantic

FT_BUF	:= ft_bufresize ft_bufnew ft_bufappend ft_bufdel ft_bufaddspace

FT_ARR	:= ft_arrfoldl ft_arriter ft_arriterl

FT_IO	:= ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr \
		ft_putnbr_fd ft_putstr ft_putstr_fd

FT_LST	:= ft_lstadd ft_lstat ft_lstcndforeach ft_lstcndremove \
		ft_lstdel ft_lstdelone ft_lstfind ft_lsthead ft_lstiter \
		ft_lstlast ft_lstmap ft_lstmerge ft_lstnew ft_lstpeekhead \
		ft_lstpeektail ft_lstpushback ft_lstpushfront \
		ft_lstpushparams ft_lstreverse ft_lstsize ft_lststart \
		ft_lsttail ft_nodedel ft_lstfoldl ft_lstsplit ft_lstmergesort \
		ft_lstfilter ft_lstseparate

FT_MEM	:= ft_bzero ft_fast_memcmp ft_fast_memcpy ft_memalloc \
		ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel \
		ft_memmove ft_memset ft_realloc ft_freeall ft_memdup \
		ft_czero

FT_MISC	:= ft_isalnum

FT_NBR	:= ft_atoi ft_isdigit ft_count_digits ft_count_digits_base \
		ft_chr_to_uint32 ft_htouint64 ft_uint8to64 ft_uint64to8

FT_STR	:=  ft_count_by_delim ft_isalpha ft_isascii ft_isprint ft_itoa \
		ft_next_delim ft_skip_delim ft_strcat ft_strchr ft_strclr \
		ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter \
		ft_striteri ft_striterl ft_strjoin ft_strlcat ft_strlen \
		ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy \
		ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit \
		ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper \
		get_next_line ft_itoa_base ft_swap ft_swap_all ft_strfoldl \
		ft_uintmaxtoa_base ft_strinsert ft_strndup ft_intmaxtoa_base \
		ft_count_char ft_wstrlen ft_wchrlen ft_str_to_unicode ft_wstr_to_str\
		ft_uint32_to_chr ft_str_from_fd ft_strfilter ft_freearr ft_strsum \
		ft_strappend ft_safeatoi ft_strjoinarrs ft_quotestr ft_stripquote

FILES	:=	$(addprefix arr/, $(FT_ARR)) \
		$(addprefix io/, $(FT_IO)) \
		$(addprefix str/, $(FT_STR)) \
		$(addprefix lst/, $(FT_LST)) \
		$(addprefix mem/, $(FT_MEM)) \
		$(addprefix nbr/, $(FT_NBR)) \
		$(addprefix buf/, $(FT_BUF)) \
		$(addprefix misc/, $(FT_MISC))

SRC		:=	$(addsuffix .c, $(FILES))

OBJ		:=	$(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(DEBUG) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@echo -n 'Compiling library functions... '
	@ar rcs $(NAME) $(OBJ)
	@echo "\033[32mdone\033[0m"

clean:
	@echo -n 'Cleaning library object files... '
	@rm -f $(OBJ) *.dSYM *.DS_Store
	@echo "\033[32mdone\033[0m"

fclean: clean
	@echo -n 'Cleaning library archive file... '
	@rm -f $(NAME)
	@echo "\033[32mdone\033[0m"

re: fclean all
	@echo -n 'Compiling archive... '
	@ranlib $(NAME)
	@echo "\033[32mdone\033[0m"
