/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:39:37 by adugain           #+#    #+#             */
/*   Updated: 2023/02/22 18:14:28 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_in_a(t_pile **pile_a, t_pile **pile_b)
{
	int	size_pile;
	int	pushed;

	pushed = 0;
	size_pile = get_size(*pile_a);
	while(size_pile - pushed > 3)
	{
		pb(pile_a, pile_b);
		pushed++;
	}
}
void	big_sort(t_pile **pile_a, t_pile **pile_b)
{
	three_in_a(pile_a, pile_b);
	if (get_size(*pile_b) == 6)
	{
		small_sort(pile_a);
		small_sort(pile_b);
	}
	else
		small_sort(pile_a);
	while(*pile_b)
	{
		get_target_pos(pile_a, pile_b);
		get_cost(pile_a, pile_b);
		*pile_b = (*pile_b)->next;
	}
}