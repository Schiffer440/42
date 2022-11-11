/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:01:22 by adugain           #+#    #+#             */
/*   Updated: 2022/11/10 14:01:23 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
    {
        size_t	i;

		i = 0;
		while(i < (n))
        {
			if(s1[i] != s2[i])
                return(s1[i] - s2[i]);
            else
                i++;
        }
        return(0);
    }