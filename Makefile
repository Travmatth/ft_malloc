ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
DEBUG =
ifdef TEST
		DEBUG = -g -fsanitize=address -fsanitize=undefined
else
		DEBUG =
endif
ifdef LEAKS
		DEBUG = -g
endif

NAME = libft_malloc_$(HOSTTYPE).so
CFLAGS = -Wall -Wextra -Werror -Wpedantic -fvisibility=hidden
LDFLAGS = -I./includes -shared
CORE = malloc realloc free
FILES = $(addprefix src/, $(CORE))
SRC = $(addsuffix .c, $(FILES))
OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(SUBMODULES) $(NAME)

$(SUBMODULES):
		@git submodule init
		@git submodule update

$(OBJ): %.o: %.c
		@$(CC) -c $(DEBUG) -I. $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
		@echo -n 'Compiling ft_malloc... '
		@$(CC) $(DEBUG) $(CFLAGS) $(LDFLAGS) $^ -o $@
		@rm -f libft_malloc.so
		@ln -s $(NAME) libft_malloc.so
		@echo "\033[32mdone\033[0m"

clean:
		@echo -n 'Cleaning ft_malloc object files... '
		@rm -rf $(OBJ) *.dSYM *.DS_Store *.so
		@echo "\033[32mdone\033[0m"

fclean: clean
		@echo -n 'Cleaning ft_malloc executable... '
		@rm -rf *.so $(NAME)
		@echo "\033[32mdone\033[0m"

re: fclean all