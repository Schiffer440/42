/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:44:24 by adugain           #+#    #+#             */
/*   Updated: 2023/02/21 14:24:33 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile *pile)
{
	t_pile	*tmp;

	while (pile)
	{
		tmp = pile->next;
		ft_printf("val:%d | index:%d\n", pile->val, pile->index);
		pile = tmp;
	}
}