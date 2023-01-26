/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:24 by adugain           #+#    #+#             */
/*   Updated: 2023/01/26 17:27:31 by adugain          ###   ########.fr       */
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

void	chunks(t_pile *piles, int j)
{
	int	min;
	int	max;
	int	i;

	min = 0;
	max = 19;
	i = piles->size_a;
	while (piles->size_a >= 0)
	{
		if (piles->stack_a[i] >= min && piles->stack_a[i] <= max
			|| piles->stack_a[i] >= min - j && piles->stack_a[i] <= max - j)
		{
			move_pile(piles, i);
			pb(piles);
			i = piles->size_a + 1;
		}
		if (piles->size_b == max)
		{
			min = max;
			max += j;
		}
		i--;
	}
}

void	sort_left(t_pile *piles, int i)
{
	while (piles->size_b != -1)
	{
		i = 0;
		while (piles->stack_b[i] != piles->size_b)
			i++;
		if (i <= piles->size_b / 2)
		{
			while (i <= piles->size_b / 2 && i != -1)
			{
				rrb(piles);
				i--;
			}
		}
		else if (i > piles->size_b / 2)
		{
			i = piles->size_b - i;
			while (i != 0)
			{
				rb(piles);
				i--;
			}
		}
		pa(piles);
	}
}

void	tri_100(t_pile *piles)
{
	int	i;

	i = 0;
	chunks(piles, 20);
	sort_left(piles, i);
}

void	tri_500(t_pile *piles)
{
	int	i;

	i = 0;
	chunks(piles, 50);
	sort_left(piles, i);
}