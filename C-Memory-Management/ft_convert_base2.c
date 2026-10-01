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
		len++;
	while (nbr <= -base_len || nbr >= base_len)
	{
		nbr = nbr / base_len;
		len++;
	}
	return (len);
}

void	ft_putnbr_base(char *result, int nbr, char *base, int len)
{
	int	base_len;
	int	remainder;

	base_len = ft_strlen(base);
	if (nbr < 0)
		result[0] = '-';
	len--;
	while (len >= (nbr < 0))
	{
		remainder = nbr % base_len;
		if (remainder < 0)
			remainder = -remainder;
		result[len] = base[remainder];
		nbr = nbr / base_len;
		len--;
	}
}
