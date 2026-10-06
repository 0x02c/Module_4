/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dloukats <loukats@student.42.tech>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 07:21:21 by dloukats          #+#    #+#             */
/*   Updated: 2026/10/06 07:27:20 by dloukats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int comp(char *s1, char *s2)
{
    int i;
    i = 0;
    while(s1[i] == s2[i] && s1[i] != '\0')
    {
        i++;
    }
    return(s1[i] - s2[i]);
}

void co_str(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;
    char *temp;

    i = 1;
    while(i < argc - 1)
    {
        if(comp(argv[i], argv[i + 1]) > 0)
        {
            temp = argv[i];
            argv[i] = argv[i + 1];
            argv[i + 1] = temp;
            i = 1;
        } 
        else
        i++;
    }

    i = 1;
    while(i < argc)
    {
        co_str(argv[i]);
        i++;
    }
    return(0);
}