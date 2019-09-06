NAME = libftprintf.a
TMP = objs
CFLAGS = -Wall -Wextra -Werror -Wpedantic
CFLAGS += -I includes/
LDFLAGS = -L ../libft/ -lft
LIBFT = ../libft/libft.a

FT_CNV  := to_chr to_dec to_flo to_hex to_oct to_ptr to_str to_uns\
		to_lit to_wch to_wst cnv_tab formatting format_nbr dec_cnv
FT_INT  := vformat parse parse_cnv color
FT_FUNC := ft_asprintf ft_dprintf ft_fprintf ft_snprintf\
		ft_vasprintf ft_vdprintf ft_vfprintf ft_vprintf ft_vsnprintf\
		ft_printf

FILES := $(addprefix conversions/, $(FT_CNV))\
		$(addprefix functions/, $(FT_FUNC))\
		$(addprefix internal/, $(FT_INT))
SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addprefix objs/, $(SRCS:.c=.o))

ifeq ($(OS),darwin)
	VERSION = darwin
else
	VERSION = generic
endif

all: $(NAME)

libftprintf_darwin.o: exported_darwin.sym $(OBJS)
	@cp $(LIBFT) ./$(NAME)
	@ld -o $@ -r -exported_symbols_list exported_darwin.sym $(OBJS)

libftprintf_generic.o: $(OBJS)
	@cp $(LIBFT) ./$(NAME)
	@ld -o $@ -r $(OBJS)

exported_darwin.sym: exported.sym
	@<$^ sed "s/^/_/" >$@

$(NAME): libftprintf_$(VERSION).o
	@echo -n 'Archiving functions... '
	@ar rcs $(NAME) $<
	@ranlib $(NAME)
	@mv $(NAME) ..
	@echo "\033[32mdone\033[0m"

$(TMP)/%.o: ./%.c
	@$(CC) $(DEBUG) $(CFLAGS) -o $@ -c $<

clean:
	@echo -n 'Cleaning printf functions... '
	@find . -name "*.o" -delete
	@rm -f exported_darwin.sym
	@rm -f libftprintf_darwin.o libftprintf_generic.o
	@echo "\033[32mdone\033[0m"

fclean: clean
	@echo -n 'Cleaning printf archive... '
	@rm -rf $(NAME)
	@echo "\033[32mdone\033[0m"
	
re: fclean all

.PHONY: all clean fclean re