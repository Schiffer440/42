/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:07:32 by adugain           #+#    #+#             */
/*   Updated: 2023/03/29 10:54:41 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char *s, ...)
{
	int	i;
	int	j;
	int	count;
	char	*list;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	list = va_arg(args, char *);
	ft_printf("%s\n", s);
	ft_printf("list:%s", list);
	while (s[i])
	{	
		j = 0;
		if (s[i] == list[j] && s[i])
			i++;
		else
		{
			while (s[i] != list[j] && s[i])
			{
				j++;
				if (s[i] != list[j] && s[i])
				{
					i++;
					j = 0;
				}	
			}
		count++;
		}
	}
	va_end(args);
	return (count);
}
