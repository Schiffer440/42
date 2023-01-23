/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:58:15 by adugain           #+#    #+#             */
/*   Updated: 2023/01/23 14:35:43 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ra(t_pile *piles)
{
	int	save;
	int	i;
	
	i = piles->size_a + 1;
	save = piles->stack_a[piles->size_a];
	while (i >= 0)
	{
		piles->stack_a[i--] = piles->stack_a[i - 1];
	}
	piles->stack_a[0] = save;
	ft_printf("ra\n");
}

void	rb(t_pile *piles)
{
	int	save;
	int	i;
	
	i = piles->size_b + 1;
	save = piles->stack_b[piles->size_b];
	while (i >= 0)
	{
		piles->stack_b[i--] = piles->stack_b[i - 1];
	}
	piles->stack_b[0] = save;
	ft_printf("rb\n");
}

void	rr(t_pile *piles)
{
	ra(piles);
	rb(piles);
	ft_printf("rr\n");
}