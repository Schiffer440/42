/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:06:12 by adugain           #+#    #+#             */
/*   Updated: 2022/11/15 12:06:41 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"



char    *ft_strjoin(char const *s1, char const *s2)
{
        char *str;
        int i;
        int j;

        i = 0;
        j = 0;
        str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
            if(!str)
                return(0);
        while(s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        while(s2[j])
        {
          str[i] = s2[j];
          i++;
          j++;
        }
        str[i] = '\0';
    return(str);
}