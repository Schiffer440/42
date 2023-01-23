/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:04:33 by adugain           #+#    #+#             */
/*   Updated: 2023/01/23 14:36:05 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rra(t_pile *piles)
{
	int	save;
	int	i;
	
	i = -1;
	save = piles->stack_a[0];
	while (++i <= piles->size_a)
	{
		piles->stack_a[i] = piles->stack_a[i + 1];
	}
	piles->stack_a[piles->size_a] = save;
	ft_printf("rra\n");
}

void	rrb(t_pile *piles)
{
	int	save;
	int	i;
	
	i = -1;
	save = piles->stack_b[0];
	while (++i <= piles->size_b)
	{
		piles->stack_b[i] = piles->stack_b[i + 1];
	}
	piles->stack_b[piles->size_a] = save;
	ft_printf("rrb\n");
}

void	rrr(t_pile *piles)
{
	rra(piles);
	rrb(piles);
	ft_printf("rrr\n");
}