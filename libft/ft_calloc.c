/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:54:41 by adugain           #+#    #+#             */
/*   Updated: 2022/11/14 14:54:43 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
    {
        void *ptr;
        
        ptr=malloc(nmemb * size);
            if (!ptr)
		        return (0);
        ft_bzero(ptr, nmemb);
    return(ptr);
    }