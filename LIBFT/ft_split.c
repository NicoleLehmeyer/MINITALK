/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:34:34 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/02 09:34:36 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//*s : string to be split
//c  : delimiter character
//RETURN : array of new strings resulting from the split.
//NULL : if allocation fails
//USE : malloc & free
//Mallocates, return array of strings [2d] by splitting *s, c delimiter
//Array must end with NULL pointer

static int	totalcharindest(char const *s, char c)
{
	int	totalchar;

	totalchar = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			totalchar++;
			while (*s && *s != c)
				s++;
		}
	}
	return (totalchar);
}

static char	*malloccpy_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc(i + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		words;
	int		j;

	if (!s)
		return (NULL);
	words = totalcharindest(s, c);
	ret = malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ret[j] = malloccpy_word(s, c);
			j++;
			while (*s && *s != c)
				s++;
		}
	}
	ret[j] = (NULL);
	return (ret);
}
