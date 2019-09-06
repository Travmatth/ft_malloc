/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:59:27 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/30 19:07:04 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** cmp_desc
** helper function given to linked lists to compare file descriptor structs
** returns 1 if given descriptor struct is valid and matches the desired
** file descriptor, 0 otherwise
*/

int			cmp_desc(void *descriptor, void *reference, size_t size)
{
	int		desired;
	int		current;

	if (size == 0 || !descriptor || !reference)
		return (0);
	desired = *(int*)reference;
	current = ((t_gnl_fd*)descriptor)->fd;
	return (size && desired == current);
}

/*
** mk_fd
** allocates and returns null or a new file descriptor struct
*/

t_gnl_fd	*mk_fd(int fd)
{
	t_gnl_fd	*f;

	if (!(f = ft_memalloc(sizeof(t_gnl_fd))))
		return (0);
	f->buf = 0;
	f->fd = fd;
	return (f);
}

/*
** resize
** creates a new string, copies src_1 in, appends src_2, then frees src_1.
** returns: a char * to the newly allocated string
** char *src_1: first string to be copied
** char *src_2: second string to be copied, then freed
** int	skip: 0|1 if true, then src_1 will ignore characters before first EOL
** int	truncate: 0|1 if true, then src_2 copied until first EOL char found
*/

char		*resize(char *src_1, char *src_2, int skip, int truncate)
{
	char	*tmp;
	char	*last_1;
	char	*last_2;
	char	*pos;
	char	*ptr;

	last_1 = src_1 ? src_1 + ft_strlen(src_1) : 0;
	last_2 = src_2 ? src_2 + ft_strlen(src_2) : 0;
	tmp = NULL;
	pos = NULL;
	if (skip)
		pos = ft_strchr(src_1, EOL) ? ft_strchr(src_1, EOL) + 1 : last_1;
	if (truncate && ft_strchr(src_2, EOL))
		last_2 = ft_strchr(src_2, EOL);
	if (!(tmp = ft_strnew((last_1 - (tmp ? tmp : src_1)) + (last_2 - src_2))))
		return (NULL);
	ptr = tmp;
	ft_memcpy(tmp, pos ? pos : src_1, last_1 - (pos ? pos : src_1));
	tmp += (last_1 - (pos ? pos : src_1));
	ft_memcpy(tmp, src_2, last_2 - src_2);
	ft_strdel(&src_1);
	return (ptr);
}

/*
** next_line
** attempts one read from open file, appends to internal buffer
** then attempts to copy one line from internal buffer to output line
** t_gnl_fd f: struct with info about current file descriptor
** t_lst **lst: address of linked list containing all file descriptors
** returns
**     1: a line has been read
**     0: the reading has been completed
**     -1: an error has happened
*/

int			next_line(t_gnl_fd *f, t_list **lst)
{
	char	*buf;
	int		seen;
	size_t	len;
	char	*eol;

	buf = ft_strnew(BUFF_SIZE);
	if (!(buf) || ERR(seen = read(f->fd, buf, BUFF_SIZE))
				|| !(f->buf = resize(f->buf, buf, FALSE, FALSE)))
		return (-1);
	ft_strdel(&buf);
	if (!(len = LEN(f->buf, 0)) && seen == 0 && !f->to_read)
	{
		ft_strdel(&(f->buf));
		ft_lstcndremove(lst, (void*)&f->fd, cmp_desc);
		return (0);
	}
	eol = ft_strchr(f->buf, EOL);
	if (len > 0)
	{
		if (!(*(f->line) = resize(*(f->line), f->buf, FALSE, TRUE)))
			return (-1);
		f->to_read = 1;
		f->buf = resize(f->buf, NULL, TRUE, FALSE);
	}
	return (!eol && !*(f->buf) && len >= BUFF_SIZE ? next_line(f, lst) : 1);
}

/*
** get_next_line
** creates or retrieves a static linked list containing info on all file
** descriptors, then create/retrieve t_gnl_fd struct on fd passed as parameter
** calls next_line, which will read next available line from file into **line
** return
**     1: a line has been read
**     0: the reading has been completed
**     -1: an error has happened
*/

int			get_next_line(const int fd, char **line)
{
	t_gnl_fd		*f;
	static t_list	*lst;
	char			*next;
	t_list			*tmp_list;

	if (fd < 0 || !line)
		return (-1);
	if (!lst)
	{
		f = mk_fd(fd);
		tmp_list = ft_lstnew(f, sizeof(t_gnl_fd));
		ft_strdel((char**)&f);
		lst = ft_lststart(&lst, tmp_list);
	}
	next = (char*)ft_lstfind(lst, (void*)&fd, cmp_desc);
	if (!(next) || !(f = (t_gnl_fd*)((t_list*)next)->content))
		f = ft_lstfind(ft_lststart(&lst, ft_lstnew(mk_fd(fd)
						, sizeof(t_gnl_fd))), (void*)&fd, cmp_desc)->content;
	f->line = line;
	f->to_read = 0;
	*(f->line) = NULL;
	return (next_line(f, &lst));
}
