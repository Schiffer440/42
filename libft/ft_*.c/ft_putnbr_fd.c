/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:03:03 by adugain           #+#    #+#             */
/*   Updated: 2022/11/16 17:03:05 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	i;

	i = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
	}
	if (i / 10)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + 48, fd);
}