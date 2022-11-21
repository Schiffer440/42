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
static int wordcount(char *s, char c)
    {
        int i;
        int count;

        i = 0;
        while(s[i])
            {
                if(s[i] == c)
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

char *filltab(char *s, char c)
    {
        int start;
        int i;
        char *str

        i = 0;
        while(s[i])
            {
                if(s[i] == c)
                    i++;
                else
                {
                    while(s[i] != c && s[i])
                        i++;
                    start++;
                }
            }
    }

char **ft_split(char const *s, char c)
    {
        int i;
        char **tab;
        char *str;
        int count;
        int tabcount;

        i = 0;
        tabcount = wordcount(str, c);
        str = (char *)s;
        tab = malloc(sizeof(char) * tabcount + 1);
            if(!tab)
                return(0);
        while(count < wordcount(str, c))
            {
                    tab[count] = filltab(str, c)
            }
    }