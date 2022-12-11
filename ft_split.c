/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:22:57 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/08 16:06:57 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size(char const *s, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static char	**ft_free(char **split, size_t word)
{
	while (word-- > 0)
		free(split[word]);
	free(split);
	return (NULL);
}

static char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n_word;
	size_t	word;
	int		x;
	int		size;

	word = -1;
	x = 0;
	n_word = ft_count_size(s, c);
	split = (char **)malloc((n_word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (++word < n_word)
	{
		while (s[x] == c)
			x++;
		size = ft_size_word(s, c, x);
		split[word] = ft_substr(s, x, size);
		if (!split[word])
			return (ft_free(split, word));
		x += size;
	}
	split[word] = 0;
	return (split);
}
