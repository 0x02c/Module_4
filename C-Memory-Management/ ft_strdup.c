/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 05:53:24 by 0x2c              #+#    #+#             */
/*   Updated: 2026/10/02 00:05:39 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Redo_Learn again !


#include <stdlib.h>
char *ft_strdup(char *src)
{
    int i;
    char *copy;

    i = 0;

    while(src[i] != '\0')
        i++;

    copy = malloc(sizeof(char) * (i + 1));
    if(copy == NULL)
        return(NULL);

    
    i = 0;

    while(src[i] != '\0')
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}













/*
char *ft_strdup(char *src)
{
    char *copy;
    int i;

    i = 0;
    while (src[i] != '\0')
        i++;

    copy = malloc(sizeof(char) * (i + 1));
    if(copy == NULL)
        return (NULL);

    i = 0;
    while (src[i] != '\0')
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';

    return (copy);
}
*/
