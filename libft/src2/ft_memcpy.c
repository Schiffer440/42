/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:33:26 by adugain           #+#    #+#             */
/*   Updated: 2022/11/09 10:33:28 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
    {
        long unsigned int i;

        i = 0;
        while(i < n)
            {
                *((char *)dest + i) = *((char *) src + i);
                i++;
            }
        return(dest);
    }