#include <stdlib.h>

int	ft_strlen(char *str);
int	check_base(char *base);
int	ft_atoi_base(char *nbr, char *base);
int	get_len_base(int nbr, int base_len);
void	ft_putnbr_base(char *result, int nbr, char *base, int len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	int		len;
	char	*result;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	len = get_len_base(number, ft_strlen(base_to));
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	ft_putnbr_base(result, number, base_to, len);
	return (result);
}
