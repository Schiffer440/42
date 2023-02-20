/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:24 by adugain           #+#    #+#             */
/*   Updated: 2023/02/08 16:59:38 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pile(t_pile *p, int i)
{
	int	j;

	j = 0;
	if (i < (p->s_a / 2))
	{
		while (j < i)
		{
			rra(p);
			j++;
		}	
	}
	else if (i > (p->s_a / 2))
	{
		while (j < (p->s_a - i))
		{
			ra(p);
			j++;
		}
	}
}

void	chunks(t_pile *p, int j)
{
	int	min;
	int	max;
	int	i;

	min = 0;
	max = 19;
	i = p->s_a;
	while (p->s_a >= 0)
	{
		if (p->a[i] >= min && p->a[i] <= max
			|| p->a[i] >= min - j && p->a[i] <= max - j)
		{
			move_pile(p, i);
			pb(p);
			i = p->s_a + 1;
		}
		if (p->s_b == max + 1)
		{
			min = max + 1;
			max += j;
		}
		i--;
	}
}

void	sort_left(t_pile *p, int i)
{
	while (p->s_b != -1)
	{
		print_pile(p);
		sleep(1);
		i = 0;
		while (p->b[i] != p->s_b)
			i++;
		if (i <= p->s_b / 2)
		{
			while (i <= p->s_b / 2 && i != -1)
			{
				rrb(p);
				i--;
			}
		}
		else if (i > p->s_b / 2)
		{
			i = p->s_b - i;
			while (i != 0)
			{
				rb(p);
				i--;
			}
		}
		pa(p);
	}
}

void	tri_100(t_pile *p)
{
	int	i;

	i = 0;
	chunks(p, 20);
	sort_left(p, i);
}

void	tri_500(t_pile *p)
{
	int	i;

	i = 0;
	chunks(p, 50);
	sort_left(p, i);
}