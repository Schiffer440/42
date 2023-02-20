/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:06:49 by adugain           #+#    #+#             */
/*   Updated: 2023/01/16 15:51:21 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += format(str[i + 1], args);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}