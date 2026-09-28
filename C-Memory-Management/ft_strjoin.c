/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:08:44 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 15:09:04 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	int		j;
	int		pos;

	if (size == 0)
	{
		result = malloc(sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			len++;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (sep[j] != '\0')
		{
			len++;
			j++;
		}
		i++;
	}

	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);

	pos = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			result[pos] = strs[i][j];
			pos++;
			j++;
		}

		if (i < size - 1)
		{
			j = 0;
			while (sep[j] != '\0')
			{
				result[pos] = sep[j];
				pos++;
				j++;
			}
		}
		i++;
	}

	result[pos] = '\0';
	return (result);
}