/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:58:28 by adugain           #+#    #+#             */
/*   Updated: 2022/11/10 10:58:29 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char *ft_strchr(const char *s, int c)
    {
        int i;

        i = 0;
        if(c == '\0')
            return((char *)s + ft_strlen(s));
        while(s[i] != '\0')
            {
                if(s[i] == c)
                    return((char *)s + i);
                else
                    i++;
            }
        return(0);
    }
