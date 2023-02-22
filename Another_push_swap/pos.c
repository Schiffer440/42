/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:23:51 by adugain           #+#    #+#             */
/*   Updated: 2023/02/22 17:57:34 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_pos(t_pile **pile)
{
	int	i;
	t_pile	*tmp;

	tmp = *pile;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target(t_pile **pile_a, int	index_b, int target_index, int target_pos)
{
	t_pile	*tmp;

	tmp = *pile_a;
	while(tmp)
	{
		if (tmp->index > index_b && tmp->index < target_index)
		{
			target_pos = tmp->pos;
			target_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmp = *pile_a;
	while (tmp)
	{
		if (tmp->index < index_b)
		{
			target_pos = tmp->pos;
			target_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	get_target_pos(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	int	target_pos;
	
	tmp = *pile_b;
	get_pos(pile_a);
	get_pos(pile_b);
	target_pos = 0;
	while (tmp)
	{
		ft_printf("targeting...\n");
		target_pos = get_target(pile_a, tmp->index, INT_MAX, target_pos);
		ft_printf("target pos:%d\n", target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp->next;
	}
	print_pile(*pile_b);
}