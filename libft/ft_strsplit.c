/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclavet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:23:33 by tclavet           #+#    #+#             */
/*   Updated: 2018/05/04 19:27:33 by tclavet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		words;
	int		j;

	i = 0;
	words = 0;
	j = 0;
	while (s[i])
	{
		if (j == 1 && s[i] == c)
			j = 0;
		if (j == 0 && s[i] != c)
		{
			j = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static int	ft_countadd_to_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	i = 0;
	j = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	while (words > 0)
	{
		words--;
		while (s[j] == c && s[j])
			j++;
		if ((tab[i] = ft_strsub(s, j, ft_countadd_to_c(s + j, c))) == NULL)
			return (NULL);
		j += ft_countadd_to_c(s + j, c);
		i++;
		tab[i] = 0;
	}
	tab[i] = NULL;
	return (tab);
}
