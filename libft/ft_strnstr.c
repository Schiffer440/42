/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:42:21 by adugain           #+#    #+#             */
/*   Updated: 2022/11/14 11:42:23 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char    *ft_strnstr(const char *big, const char *little, size_t len)
    {
        size_t i;
        size_t j;

        i = 0;
        j = 0;
        if((little[j] == '\0'))
            return((char *)big);
        while(i < len)
        {
            while(little[j] == big[i + j])
                {
                    if(little[j + 1] == '\0')
                        return((char *)big + i);
                    else
                        j++;
                }
        i++;
        }
    return(0);
    }