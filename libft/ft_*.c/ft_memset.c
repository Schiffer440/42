/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:35:47 by adugain           #+#    #+#             */
/*   Updated: 2022/11/08 16:35:48 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void *ft_memset(void *s, int c, size_t n)
    {
        long unsigned int   i;

        i = 0;
        while(i < n)
        {
            *((char *)s + i) = c;
           i++;
        }
        return(s);
    }