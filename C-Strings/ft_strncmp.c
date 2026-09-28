/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 06:09:58 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 06:12:33 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;
    i = 0;

    while(i < n && s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }

    if(i == n)
        return (0);
    return((unsigned char)s1[i] - (unsigned char)s2[i]);
}