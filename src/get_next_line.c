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

#include "../libft/includes/libft.h"
#include "../include/get_next_line.h"

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

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE];
	int				ret;
	static t_list	*file;
	t_list			*link;
	int				i;

	link = get_link(&file, fd);
	i = ft_strlen(link->content);
	if ((*line = ft_strnew(i)) == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((link->content = ft_strjoin(link->content, buf)) == NULL)
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ft_strlen(link->content) == 0)
		return (0);
	//write_content_line(link, line, i);
	*line = ft_strcpy(*line, link->content);
	return (1);
}
