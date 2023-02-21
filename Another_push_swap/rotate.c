/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:05:52 by adugain           #+#    #+#             */
/*   Updated: 2023/02/21 15:02:27 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	rotate(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*last;

	tmp = *pile;
	*pile = (*pile)->next;
	last = pile_last(*pile);
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_pile **pile_a)
{
	rotate(pile_a);
	ft_printf("ra\n");
}

void	rb(t_pile **pile_b)
{
	rotate(pile_b);
	ft_printf("rb\n");
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_printf("rr\n");
}