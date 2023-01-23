/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:21:45 by adugain           #+#    #+#             */
/*   Updated: 2023/01/23 14:35:16 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sa(t_pile *piles)
{
	int save;
	
	save = piles->stack_a[piles->size_a];
	piles->stack_a[piles->size_a] = piles->stack_a[piles->size_a - 1];
	piles->stack_a[piles->size_a - 1] = save;
	ft_printf("sa\n");
}

void	sb(t_pile *piles)
{
	int save;
	
	save = piles->stack_b[piles->size_b];
	piles->stack_b[piles->size_b] = piles->stack_a[piles->size_b - 1];
	piles->stack_b[piles->size_b - 1] = save;
	ft_printf("sb\n");
}

void	ss(t_pile *piles)
{
	sa(piles);
	sb(piles);
	ft_printf("ss\n");
}