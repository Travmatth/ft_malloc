/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:34:43 by tmatthew          #+#    #+#             */
/*   Updated: 2019/04/26 15:26:17 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include "constants.h"

/*
** C Data Types
*/

# define LI long int
# define LLI long long int
# define I_SIZE (sizeof(int))
# define I_MIN 0x80000000
# define I_MAX 0x7FFFFFFF
# define S_MIN -0x8000
# define S_MAX 0x7FFF
# define C_SIZE (sizeof(char))
# define LI_SIZE (sizeof(LI))
# define LLI_SIZE (sizeof(LLI))
# define LI_MAX 2147483647
# define LI_MIN -2147483648
# define C_BIT 8

/*
** Nonzero if either X or Y is not aligned on a "long" boundary.
*/

# define NOT_LONG_BOUNDARY(X) (((long)X & (sizeof (long) - 1)))
# define UNALIGNED(X, Y) (NOT_LONG_BOUNDARY(X) | NOT_LONG_BOUNDARY(Y))

/*
** How many bytes are copied each iteration of the 4X unrolled loop.
*/

# define BIGBLOCKSIZE (sizeof (long) << 2)

/*
** How many bytes are copied each iteration of the word copy loop.
*/

# define LITTLEBLOCKSIZE (sizeof (long))

/*
** Threshold for punting to the byte copier.
*/

# define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)

/*
** defines
*/

# define OCT_VALUES "01234567"
# define HEX_VALUES_LOWER "0123456789abcdef"
# define HEX_VALUES_UPPER "0123456789ABCDEF"
# define IS_SEPARATOR(c, str) (c == str)
# define LEN(x, default) (x && *x ? ft_strlen(x) : default)
# define EOL '\n'
# define ERR(x) (x == -1)
# define NONE(x) (x == 0)
# define OK(x) (x > 0)
# define NIL 0
# define ERROR -1
# define SUCCESS 1
# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 32
# define LESSER(x, y) (x < y ? x : y)
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BITMASK(b) (1 << ((b) % C_BIT))
# define BITSLOT(b) ((b) / C_BIT)
# define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
# define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
# define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
# define BITNSLOTS(nb) ((nb + C_BIT - 1) / C_BIT)

typedef struct			s_gnl_fd
{
	int					fd;
	char				**line;
	char				to_read;
	char				*buf;
}						t_gnl_fd;

/*
** buf functions
*/

typedef struct			s_buf
{
	void				*buf;
	size_t				current;
	size_t				total;
}						t_buf;

t_buf					*ft_bufresize(t_buf *b);
t_buf					*ft_bufnew(void *data, size_t current, size_t total);
t_buf					*ft_bufappend(t_buf *b, void *new, size_t added_size);
void					ft_bufdel(t_buf **b);
t_buf					*ft_bufaddspace(t_buf *b, size_t i);

/*
** memory functions
*/

void					ft_czero(void *ptr, char c, size_t len);
void					*ft_memdup(const void *buffer, size_t len);
void					ft_freeall(int total, ...);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst
									, const void *src
									, int c
									, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					*ft_realloc(void **ptr, size_t size);
void					ft_memdel(void **ap);
void					*ft_fast_memcpy(void *dst, const void *src, size_t n);
int						ft_fast_memcmp(const void *s1
									, const void *s2
									, size_t n);

/*
** String functions
*/

size_t					ft_str_from_fd(int fd, char **str);
size_t					ft_wstrlen(wchar_t *w_str);
int						ft_wchrlen(wchar_t c);
void					ft_str_to_unicode(wchar_t c, char *s);
char					*ft_wstr_to_str(wchar_t *ws);
size_t					ft_count_char(const char *string, char c);
char					*ft_strndup(const char *s1, int len);
char					*ft_strinsert(const char *str
									, const char *text
									, size_t index);
char					*ft_swap(const char *str
								, const char *old
								, const char *new);
char					*ft_swap_all(const char *str
								, const char *old
								, const char *new);
int						get_next_line(const int fd, char **line);
char					*ft_skip_delim(char const *str, char delim);
size_t					ft_count_by_delim(char const *s, char c);
char					*ft_next_delim(char const *string, char delim);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack
									, const char *needle
									, size_t len);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s
								, char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s
								, unsigned int start
								, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *string, char delim);
char					*ft_striterl(void (*f)(void *elem, size_t i, int *stop)
									, char *str);
char					*ft_itoa(int n);
char					*ft_itoa_base(int n, int base);
void					*ft_strfoldl(void *(*f)(void *final
												, char elem
												, size_t i
												, int *stop)
									, size_t len
									, char *arr);
char					*ft_uintmaxtoa_base(uintmax_t nbr
											, int8_t base
											, const char *lookup);
char					*ft_intmaxtoa_base(intmax_t nbr
											, int8_t base
											, const char *lookup);
unsigned char			*ft_uint32_to_chr(unsigned char *output
							, uint32_t *input
							, unsigned int len);
char					*ft_strfilter(int (*f)(char elem
												, size_t i
												, char *str
												, int *stop)
									, char *str);
void					ft_freearr(char **arr, int free_parent);
char					*ft_strsum(char **strings, char *fill);
char					**ft_strappend(char **strings, char *string);
int						ft_safeatoi(char *num, int *number);
char					**ft_strjoinarrs(char **arr_1, char **arr_2);
char					*ft_quotestr(char *str, char quote);
char					*ft_stripquote(char *str);

/*
** String functions
** Function ideas: should implement as necessary
** {multi} mean it should take a list of f(x)'s and variable num of args
** char *ft_strscan(t_list *lst, t_list *(*f)(t_list *elem));
** char *ft_strmap(char *str, );
** char *ft_strjoin(char *str, );
** char *ft_striterr(char *str, );
** char *ft_strfilter(char *str, );
** char *ft_strfoldl(char *str, );
** char *ft_strfoldl(char *str, );
** char *ft_strfoldl_new(char *str, );
** char *ft_strzip(char *str, );
** char *ft_strzip_with(char *str, );
** char *ft_strreverse(char *str, );
** char *ft_strreduce(char *str, );
**
** char *ft_strmap_all();
** char *ft_strjoin_all();
** char *ft_striter_all();
** char *ft_strfilter_all();
** char *ft_strfoldl_all();
** char *ft_strfold_all();
** char *ft_strfold_new_all();
** char *ft_strzip_all();
** char *ft_strzip_with_all();
** char *ft_strreverse_all();
** char *ft_strreduce_all(char *str, );
*/

/*
** List functions
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lststart(t_list **alst, t_list *new);
t_list					*ft_lstat(t_list *begin_list, unsigned int nbr);
t_list					*ft_lstfind(t_list *begin_list
									, void *data_ref
									, int (*cmp)());
t_list					*ft_lstlast(t_list *begin_list);
void					ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
t_list					*ft_lstpushback(t_list **begin_list, t_list *node);
t_list					*ft_lstpushfront(t_list **begin_list, t_list *node);
t_list					*ft_lstpushparams(int ac, char **av);
t_list					*ft_lstcndremove(t_list **begin_list
										, void *data
										, int (*cmp)());
void					ft_lstreverse(t_list **begin_list);
int						ft_lstsize(t_list *begin_list);
t_list					*ft_lstpeekhead(t_list *begin_list);
t_list					*ft_lstpeektail(t_list *begin_list);
t_list					*ft_lsthead(t_list **begin_list);
t_list					*ft_lsttail(t_list **begin_list);
void					ft_nodedel(void *node, size_t i);
void					*ft_lstfoldl(void *(*f)(void *final
												, t_list *elem
												, size_t i
												, int *stop)
									, t_list *list);
t_list					*ft_lstmergesort(int (*f)(void *first, void *second),
									t_list *list, int reverse, size_t size);
t_list					*ft_lstsplit(t_list *list, int index);
t_list					*ft_lstfilter(t_list *list
									, int (*f)(t_list *elem)
									, void (*del)(void *, size_t));
t_list					*ft_lstseparate(t_list **list, int (*f)(t_list *elem));

/*
** List functions
** Function ideas: should implement as necessary
** {all} mean_all it should take a list of f(x)'s and variable num of args
** t_list *ft_lstscan(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstjoin(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstiter(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfold(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfold(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfold_new(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstzip(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstzip_with(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstreverse(t_list *lst, t_list *(*f)(t_list *elem));
**
** t_list *ft_lstmap_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstjoin_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstiter_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfilter_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfoldld_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfoldld_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstfoldld_new_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstzip_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstzip_with_all(t_list *lst, t_list *(*f)(t_list *elem));
** t_list *ft_lstreverse_all(t_list *lst, t_list *(*f)(t_list *elem));
*/

/*
** Array functions
*/

void					*ft_arriterl(void *(*f)(void *elem, size_t i, int *stop)
										, size_t len
										, size_t step
										, void *arr);
void					*ft_arrfoldl(void *(*f)(void *final
												, void *elem
												, size_t i
												, int *stop)
									, size_t len
									, size_t step
									, void *arr);

/*
** implement once able to use stdarg.h
** void *ft_arrscan(t_list *lst, t_list *(*f)(t_list *elem));
** void *ft_arriter_all(t_lambda f[], size_t len, size_t step, void *arr);
** void *ft_arrfoldr(void *arr, size_t len, size_t step);
** void *ft_arrfoldr_new(void *arr, size_t len, size_t step);
** void *ft_arrfoldl_all(void *arr, size_t len, size_t step);
** void *ft_arrfoldr_all(void *arr, size_t len, size_t step);
** void *ft_arrfoldr_new_all(void *arr, size_t len, size_t step);
*/

/*
** Function ideas: should implement as necessary
** {all} should take a list of f(x)'s and variable num of args
** void *ft_arrmap(void *arr, size_t len, size_t step);
** void *ft_arrjoin(void *arr, size_t len, size_t step);
** void *ft_arrfilter(void *arr, size_t len, size_t step);
** void *ft_arrzip(void *arr, size_t len, size_t step);
** void *ft_arrzip_with(void *arr, size_t len, size_t step);
** void *ft_arrreverse(void *arr, size_t len, size_t step);
**
** void *ft_arrmap_all(void *arr, size_t len, size_t step);
** void *ft_arrjoin_all(void *arr, size_t len, size_t step);
** void *ft_arrfilter_all(void *arr, size_t len, size_t step);
** void *ft_arrzip_all(void *arr, size_t len, size_t step);
** void *ft_arrzip_with_all(void *arr, size_t len, size_t step);
** void *ft_arrreverse_all(void *arr, size_t len, size_t step);
*/

/*
** io functions
*/

void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);

/*
** nbr functions
*/

int						ft_atoi(char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_count_digits(int number);
int						ft_count_digits_base(int number, int base);
uint32_t				*ft_chr_to_uint32(uint32_t *output
							, unsigned char *input
							, unsigned int len);
uint8_t					*ft_uint64to8(uint64_t block, uint8_t *out);
uint64_t				ft_uint8to64(uint8_t *block);
int						ft_htouint64(uint8_t *hex, uint64_t *val);

/*
** Function ideas: should implement as necessary
** {multi} mean it should take a list of f(x)'s and variable num of args
** https://github.com/OpenGenus/cosmos has common data structures and algos
**
** Misc functions
*/

#endif
