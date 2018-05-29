/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclavet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:22:28 by tclavet           #+#    #+#             */
/*   Updated: 2018/05/04 19:36:50 by tclavet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		len;
	char	*cmp;
	int		i;

	i = 0;
	len = ft_strlen(src);
	if ((cmp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (src[i])
	{
		cmp[i] = src[i];
		i++;
	}
	cmp[i] = '\0';
	return (cmp);
}
