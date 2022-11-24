/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:01:05 by adugain           #+#    #+#             */
/*   Updated: 2022/11/24 11:33:36 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
	{
		char	*str;
		int	i;
		int len;


		len = ft_strlen(s);
		i = 0;
		str = malloc(sizeof(char) * len + 1);
		if(!str)
			return(0);
		while(i < len)
		{
			str[i]=(*f)(i, s[i]);
			i++;
		}
	str[i] = '\0';
	return(str);
	}
