/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:49:41 by adugain           #+#    #+#             */
/*   Updated: 2022/11/16 10:49:43 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
    {
        int i;
        int j;
        int a;
        char *trim;

        trim = malloc(sizeof(char) * ft_strlen(s1) + 1);
        if(!trim)
            return(0);
        i = 0;
        j = 0;
        a = 0;
        while(s1[i])
            {
                    if(s1[i] == set[j])
                        {
                            i++;
                            j++;
                        }
                    else
                    {
                        j = 0;
                        trim[a] = s1[i];
                        a++;
                        i++;
                    }
            }
        return(trim);
    }
