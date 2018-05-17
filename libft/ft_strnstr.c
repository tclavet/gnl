/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclavet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:23:26 by tclavet           #+#    #+#             */
/*   Updated: 2018/04/23 20:16:03 by tclavet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len;
	char	*ndl;
	char	*hst;

	if (*needle == '\0')
		return ((char *)haystack);
	hst = (char *)haystack;
	ndl = (char *)needle;
	len = ft_strlen(ndl);
	i = 0;
	while (hst[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp(haystack + i, needle, len) == 0)
			return (hst + i);
		i++;
	}
	return (NULL);
}
