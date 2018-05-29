/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclavet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:23:40 by tclavet           #+#    #+#             */
/*   Updated: 2018/04/23 19:24:55 by tclavet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((cpy = ft_strnew(len)) == NULL)
		return (NULL);
	while (i != start)
	{
		s++;
		i++;
	}
	cpy = ft_strncpy(cpy, s, len);
	return (cpy);
}
