/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:44:29 by adugain           #+#    #+#             */
/*   Updated: 2023/01/23 18:53:47 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_index(t_pile *piles)
{
	int	i;
	int	j;
	int	index;
	int	*tmp;
	
	i = piles->size_a;
	tmp = malloc(sizeof(int) * i);
		if (!tmp)
			return (0);
	while (i >= 0)
	{
		index = 1;
		j = piles->size_a;
		while (j >= 0)
		{
			if (piles->stack_a[i] > piles->stack_a[j])
				index++;
			j--;
		}
		tmp[i] = index;
		i--;
	}
	free(piles->stack_a);
	return (tmp);
}

int	check_piles(t_pile *piles)
{
	int	i;

	i = 0;
	while (piles->size_a > i)
	{
		if (piles->stack_a[i] > piles->stack_a[i + 1])
			i++;
		else
			return (ft_printf("nope\n"), 0);
	}
	return (ft_printf("yep\n"), 1);
}

void	tri_3(t_pile *piles)
{
	if (piles->stack_a[piles->size_a] > piles->stack_a[piles->size_a - 1])
	{
		if (piles->stack_a[piles->size_a] < piles->stack_a[0])
			sa(piles);
		else if (piles->stack_a[piles->size_a] > piles->stack_a[0]
			&& piles->stack_a[piles->size_a - 1] < piles->stack_a[0])
			ra(piles);
		if (piles->stack_a[piles->size_a - 1] > piles->stack_a[0]
			&& piles->stack_a[piles->size_a] > piles->stack_a[0])
		{
			sa(piles);
			rra(piles);
		}
	}
	else if (piles->stack_a[piles->size_a] < piles->stack_a[piles->size_a - 1])
	{
		if (piles->stack_a[piles->size_a] > piles->stack_a[0])
			rra(piles);
		else if (piles->stack_a[piles->size_a] < piles->stack_a[0])
		{
			sa(piles);
			ra(piles);
		}
	}
}

void	tri_5(t_pile *piles)
{
	piles->stack_a = ft_index(piles);
}
