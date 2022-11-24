/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:22 by adugain           #+#    #+#             */
/*   Updated: 2022/11/21 11:18:23 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdlib.h>
#include <stdio.h>*/
#include "libft.h"

static int wordcount(char *s, char c)
    {
        int i;
        int count;

        i = 0;
        count = 0;
        while(s[i] != '\0')
            {
                if(s[i] == c && s[i])
                    i++;
                else
                {
                    while(s[i] != c && s[i])
                        i++;
                count++;
                }
            }
        return(count);
    }

static char *filltab(char *s, char c)
    {
        int i;
        int len;
        char *str;

        i = 0;
        len = 0;
        while(s[i] == c)
          s++;
        while(s[i] != c && s[i])
            {
                i++;
                len++;
            }
        str = malloc(sizeof(char) * len + 1);
          if(!str)
            return(0);
        i = 0;
        while(i < len)
            {
                str[i] = s[i];
                i++;
            }
    str[i] = '\0';
    return(str);
    }

char **ft_split(char const *s, char c)
    {
        int i;
        char **tab;
        int count;
        int tabcount;

        i = 0;
        count = 0;
        tabcount = wordcount((char *)s, c);
        tab = malloc(sizeof(char *) * tabcount + 1);
            if(!tab)
                return(0);
        while(count < tabcount && s[i])
            {
                tab[count] = filltab((char *)s, c);
                while(s[i] == c && s[i])
                  s++;
                while(s[i] != c && s[i])
                    s++;
                count++;
            }
      return(tab);
    }  
/*int main(int ac, char **av) 
{
    (void)ac;
    int i;
    char **tab = ft_split(av[1], av[2][0]);

    i = 0;
    while(tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
  return (0);
}*/
