/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:52:59 by dforteza          #+#    #+#             */
/*   Updated: 2026/09/14 14:09:05 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			w++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (w);
}

static void	free_strs(char **words, int k)
{
	while (k > 0)
	{
		k--;
		free(words[k]);
	}
}

static char	*extract_word(char const *s, int start, int end)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	ft_memmove(word, (char *)s + start, end - start);
	word[end - start] = '\0';
	return (word);
}

static char	**fill_words(char const *s, char c, char **words, int w)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] && k < w)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			words[k] = extract_word(s, j, i);
			if (!words[k])
			{
				free_strs(words, k);
				return (NULL);
			}
			k++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**words;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	words = (char **)malloc(sizeof(char *) * (w + 1));
	if (!words)
		return (NULL);
	words[w] = NULL;
	if (!fill_words(s, c, words, w))
	{
		free(words);
		return (NULL);
	}
	return (words);
}
