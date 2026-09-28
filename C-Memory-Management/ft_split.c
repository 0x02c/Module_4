/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:10:31 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 15:10:41 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !is_separator(str[i], charset))
			i++;
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && !is_separator(str[len], charset))
		len++;
	return (len);
}

char	*copy_word(char *str, char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(str, charset);
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		words;
	int		i;

	words = count_words(str, charset);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);

	i = 0;
	while (i < words)
	{
		while (*str != '\0' && is_separator(*str, charset))
			str++;
		result[i] = copy_word(str, charset);
		if (result[i] == NULL)
		{
			while (i > 0)
			{
				free(result[i - 1]);
				i--;
			}
			free(result);
			return (NULL);
		}
		while (*str != '\0' && !is_separator(*str, charset))
			str++;
		i++;
	}
	result[i] = NULL;
	return (result);
}