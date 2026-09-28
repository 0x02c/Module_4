/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:07:32 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 15:08:09 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int size;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }

    size = max - min;
    *range = malloc(sizeof(int) * size);
    if (*range == NULL)
        return (-1);

    i = 0;
    while (i < size)
    {
        (*range)[i] = min + i;
        i++;
    }
    return (size);
}