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

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
        size_t i;
        char *d;
        const char *s;
	
	if(dest == 0 && src == 0) 
        	return(0);
        d = dest;
        s = src;
        i = 0;
	if(s < d)
		while(n != 0)
		{

		}
	else
		while(i < n)
            {
               d[i] = s[i];
               i++;
            }
return(dest);
}