/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:40:32 by adugain           #+#    #+#             */
/*   Updated: 2022/11/11 14:40:34 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
    {
        size_t	i;
        int j;
        char *a;
        char *b;

        a = (char *)s1;
        b = (char *)s2;

        j = 0;
		i = 0;
		while(i < n)
        {
			if(a[j] != b[j])
                return(a[j] - b[j]);
            else
            {
                i++;
                j++;
            }
        }
        return(0);
    }
