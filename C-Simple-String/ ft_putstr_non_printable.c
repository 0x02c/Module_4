/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_putstr_non_printable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c <0x2c@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:50:31 by 0x2c              #+#    #+#             */
/*   Updated: 2026/09/28 05:51:48 by 0x2c             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void ft_putstr_non_printable(char *str)
{
    int     i;
    char    *hex;

    hex = "0123456789abcdef";
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 32 && str[i] <= 126)
        {
            write(1, &str[i], 1);
        }
        else
        {
            write(1, "\\", 1);
            write(1, &hex[(unsigned char)str[i] / 16], 1);
            write(1, &hex[(unsigned char)str[i] % 16], 1);
        }
        i++;
    }
}