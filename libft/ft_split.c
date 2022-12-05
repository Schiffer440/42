/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:22 by adugain           #+#    #+#             */
/*   Updated: 2022/12/05 14:07:38 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	ft_free(char **tab, int pos)
{
	while (pos >= 0)
	{
		free(tab[pos]);
		pos--;
	}
	free(tab);
	return (0);
}

static int	wordcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i])
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
		count++;
		}
	}
	return (count);
}

static char	*filltab(char *s, char c, int count, char **tab)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s[i] == c)
		s++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		ft_free(tab, count);
		return (0);
	}
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	int		tabcount;

	if (!s)
		return (0);
	count = 0;
	tabcount = wordcount((char *)s, c);
	tab = malloc(sizeof(char *) * (tabcount + 1));
	if (!tab)
		return (0);
	while (count < tabcount && *s && filltab((char *)s, c, count, tab) != 0)
	{
		while (s[0] == c && *s)
			s++;
		if (*s)
		{
			tab[count] = filltab((char *)s, c, count, tab);
			count++;
		}
		while (s[0] != c && *s)
			s++;
	}
	tab[count] = 0;
	return (tab);
}

/*int main() 
{
    int i;
    char **tab = ft_split("  tripouille  42  ", ' ');

    i = 0;
    while(tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
  return (0);
}*/
