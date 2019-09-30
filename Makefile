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

IS_DEBUG = 
NAME = libft_malloc_$(HOSTTYPE).so
TESTNAME = malloc_test
CFLAGS = -Wall -Wextra -Werror -Wpedantic
DYLIB = -shared -exported_symbols_list exported.syms 
TESTFLAGS = -I./includes -L. -lft_malloc
CORE = malloc realloc free chunks show_alloc log utils
FILES = $(addprefix src/, $(CORE))
SRC = $(addsuffix .c, $(FILES))
OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) -c $(DEBUG) $(IS_DEBUG) -I. $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@echo -n 'Compiling ft_malloc... '
	@$(CC) $(DEBUG) $(CFLAGS) $(DYLIB) $^ -o $@
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so
	@echo "\033[32mdone\033[0m"

debug: set-debug all

set-debug:
	$(eval IS_DEBUG='-D__DEBUG__') 

test-debug: set-debug all
	@$(CC) $(IS_DEBUG) $(DEBUG) $(TESTFLAGS) $(LDFLAGS) test/$(CASE) -o $(TESTNAME)

test-logs: set-debug all
	@$(CC) $(IS_DEBUG) $(DEBUG) $(TESTFLAGS) $(LDFLAGS) test/$(CASE) -o $(TESTNAME)

test: all
	@$(CC) $(IS_DEBUG) $(DEBUG) $(TESTFLAGS) $(LDFLAGS) test/$(CASE) -o $(TESTNAME)

clean:
	@echo -n 'Cleaning ft_malloc object files... '
	@rm -rf $(OBJ) *.dSYM *.DS_Store *.so $(TESTNAME)
	@echo "\033[32mdone\033[0m"

fclean: clean
	@echo -n 'Cleaning ft_malloc executable... '
	@rm -rf *.so $(NAME)
	@echo "\033[32mdone\033[0m"

re: fclean all