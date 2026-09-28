/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:58:16 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 05:58:58 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Re-write please ( easier form )

char *ft_strcapitalize(char *str)
{
    int i;
    int new_word;

    i = 0;
    new_word = 1;
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9'))
        {
            if (new_word && str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            else if (!new_word && str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            new_word = 0;
        }
        else
        {
            new_word = 1;
        }
        i++;
    }
    return (str);
}