/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:21:45 by adugain           #+#    #+#             */
/*   Updated: 2023/01/20 13:55:20 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sa(t_pile *piles)
{
	int save;
	
	save = piles->stack_a[piles->size_a];
	piles->stack_a[piles->size_a] = piles->stack_a[piles->size_a - 1];
	piles->stack_a[piles->size_a - 1] = save;
}

void	sb(t_pile *piles)
{
	int save;
	
	save = piles->stack_b[piles->size_b];
	piles->stack_b[piles->size_b] = piles->stack_a[piles->size_b - 1];
	piles->stack_b[piles->size_b - 1] = save;
}

void	ss(void)
{
	swap_a;
	swap_b;
}