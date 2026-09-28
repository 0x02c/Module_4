/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:09:49 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 15:10:03 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	index;
	int	base_len;

	i = 0;
	sign = 1;
	result = 0;
	base_len = ft_strlen(base);

	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -sign;
		i++;
	}
	index = get_index(nbr[i], base);
	while (index != -1)
	{
		result = result * base_len + index;
		i++;
		index = get_index(nbr[i], base);
	}
	return (result * sign);
}

int	get_len_base(int nbr, int base_len)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (nbr >= base_len)
	{
		nbr = nbr / base_len;
		len++;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	int		len;
	int		base_len;
	int		sign;
	char	*result;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	base_len = ft_strlen(base_to);
	len = get_len_base(number, base_len);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	sign = 1;
	if (number < 0)
	{
		sign = -1;
		result[0] = '-';
		number = -number;
	}
	len--;
	while (len >= (sign == -1))
	{
		result[len] = base_to[number % base_len];
		number = number / base_len;
		len--;
	}
	return (result);
}