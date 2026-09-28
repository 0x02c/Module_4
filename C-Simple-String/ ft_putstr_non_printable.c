/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_putstr_non_printable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:58:16 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 16:48:20 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void ft_putstr_non_printable(char *str)
{
    int i;
    char *hex;

    hex = "0123456789abcdef";
    i = 0;

    while(str[i] != '\0')
    {
        if(!((str[i] >= 32 && str[i] <= 126)))
        {
            write(1, "\\", 1);
            write(1, &hex[(unsigned char)str[i] / 16], 1);
            write(1, &hex[(unsigned char)str[i] % 16], 1);

        } else
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}