/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:13:06 by adugain           #+#    #+#             */
/*   Updated: 2022/11/18 11:13:08 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;

	sign = 1;
	str = malloc(sizeof(char) * count(n) + 1);
	if (!str)
		return (0);
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		str[0] = '-';
		sign *= -sign;
	}
	str[count(n)] = '\0';
	while (n)
	{
		str[count(n) - 1] = n % 10 * sign + 48;
		n /= 10;
	}
	return (str);
}
