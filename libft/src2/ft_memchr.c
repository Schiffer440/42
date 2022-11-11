/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:56:21 by adugain           #+#    #+#             */
/*   Updated: 2022/11/11 12:56:22 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
    {
        long unsigned int i;
        int j;
        const char *s1;

        i = 0;
        j = 0;
        s1 = s;
        while(i < (n - 1))
            {
                if(s1[j] == c)
                    return((char *)s + i);
                else
                {
                    i++;
                    j++;
                }
            }
        return(0);
    }
