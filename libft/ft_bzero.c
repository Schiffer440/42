/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:04:09 by adugain           #+#    #+#             */
/*   Updated: 2022/11/08 17:04:10 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void ft_bzero(void *s, size_t n)
    {
        size_t  i;

        i = 0;
        while(i < n)
            {
                *((char *)s + i) = '\0';
                i++;
            }
    }
