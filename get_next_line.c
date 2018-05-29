/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclavet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:32:17 by tclavet           #+#    #+#             */
/*   Updated: 2018/05/29 20:39:42 by tclavet          ###   ########.fr       */
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
	free(mover->content);
	return (mover);
}

static int			copy_until_char(char **line, char *src, char c)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (src[i] != c && src[i])
		i++;
	if ((*line = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
	{
		free(*line);
		return (0);
	}
	while(src[j] && j < i)
	{
		line[0][j] = src[j];
		j++;
	}
	line[0][j] = '\0';
	return (i);
}

static int			move_or_false(t_list *link, int pos)
{
	if (pos < (int)ft_strlen(link->content))
	{
		link->content += pos + 1;
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_list	*file;
	t_list			*link;
	int				i;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	link = get_link(&file, fd);
	//if ((*line = ft_strnew(1)) == NULL)
	//	return (-1);
	//free(*line);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((link->content = ft_strjoin(link->content, buf)) == NULL)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && ft_strlen(link->content) == 0)
		return (0);
	dprintf(1, "gnl test 1 %s\n", *line);
	i = copy_until_char(line, link->content, '\n');
	dprintf(1, "gnl test 2 %s %d\n", *line, i);
	if (move_or_false(link, i) == 0)
		ft_strclr(link->content);
	return (1);
}
