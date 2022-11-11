/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:06:17 by adugain           #+#    #+#             */
/*   Updated: 2022/11/09 12:06:19 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
    {
        long unsigned int i;
        const char *s;

        s = src;
        i = 0;
        while(i < n)
            {
               *((char *)s + i) = *((char *)dest + i);
               i++;
            }
        return(dest);
    }