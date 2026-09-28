/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0x2c@HACK_CC.42.EU </connectSRC>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 15:06:30 by 0x2c@HACK_C       #+#    #+#             */
/*   Updated: 2026/09/28 15:07:14 by 0x2c@HACK_C      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *array;
    int i;

    if (min >= max)
        return (NULL);

    array = malloc(sizeof(int) * (max - min));
    if (array == NULL)
        return (NULL);

    i = 0;
    while (min < max)
    {
        array[i] = min;
        i++;
        min++;
    }
    return (array);
}