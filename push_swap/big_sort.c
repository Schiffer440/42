/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:24 by adugain           #+#    #+#             */
/*   Updated: 2023/01/24 17:54:47 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	move_pile(t_pile *piles, int i)
{
	int	j;
	
	j = 0;
	if (i < (piles->size_a / 2))
	{
		while (j < i)
		{
			rra(piles);
			j++;
		}	
	}
	else if (i > (piles->size_a / 2))
	{
		while (j < (piles->size_a - i))
		{
			ra(piles);
			j++;
		}
	}
}
void	chunks(t_pile *piles)
{
	int	min;
	int	max;
	int	i;
	
	min = 0;
	max = 19;
	i = piles->size_a;
	while (piles->size_a != 0)
	{
		//sleep(1);
		if (piles->stack_a[i] >= min && piles->stack_a[i] <= max)
		{
			ft_printf("nb :%d | i:%d\n", piles->stack_a[i], i);
			move_pile(piles, i);
			pb(piles);
			i = piles->size_a + 1;
			print_pile(piles);
		}
		if (piles->size_b == max)
		{
			min = max;
			max += 20;
		}
		i--;
	}
	
}
void	tri_100(t_pile *piles)
{
	chunks(piles);
}
