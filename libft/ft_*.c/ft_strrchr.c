/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:29:47 by adugain           #+#    #+#             */
/*   Updated: 2022/11/10 11:29:48 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char *ft_strrchr(const char *s, int c)
    {
        int l;
        int i;

        i = 0;
        l = ft_strlen(s);
        if(s[i] == '\0')
            return(0);
        if(c == '\0')
            return((char *)s + l);
        while(l - 1 > 0)
            {
                if(s[l] == c)
                    return((char *)s + l);
                else
                    l--;
            }
        return(0);
    }