/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclavet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:32:17 by tclavet           #+#    #+#             */
/*   Updated: 2018/05/19 18:28:23 by tclavet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"

static t_list		*get_link(t_list **file, int fd)
{
	t_list			*mover;

	mover = *file;
	while (mover)
	{
		if ((int)mover->content_size == fd)
			return (mover);
		mover = mover->next;
	}
	mover = ft_lstnew("\0", fd);
	ft_lstadd(file, mover);
	mover = *file;
	return (mover);
}

int				copy_until_char(char *line, char *src, char c)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (src[i] != c)
		i++;
	dprintf(1, "Pos %d\n", i);
	if ((line = ft_strnew(i)) == NULL)
		return (0);
	dprintf(1, "Test copy\n");
	while(src[j] && j < i)
	{
		line[j] = src[j];
		j++;
	}
	dprintf(1, "Test copy done \n");
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*file;
	t_list			*link;
	int				i;

	int	test = 0; //DELETE

	link = get_link(&file, fd);
	dprintf(1, "Test %d\n", test++);
	if ((*line = ft_strnew(1)) == NULL)
		return (-1);
	dprintf(1, "Test %d\n", test++);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((link->content = ft_strjoin(link->content, buf)) == NULL)
			return (-1);
		ft_putstr(ft_strchr(buf, '\n'));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	dprintf(1, "Test %d\n", test++);
	ft_putstr(link->content);
	dprintf(1, "Test %d\n", test++);
	i = copy_until_char(*line, link->content, '\n');
	dprintf(1, "Test %d\n", test++);
	if (ret < BUFF_SIZE && ft_strlen(link->content) == 0)
		return (0);
	return (1);
}
