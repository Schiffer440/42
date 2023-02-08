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

static int	scan_pile(t_pile *p, int *min)
{
	int	i;
	
	i = 0;
	if (p->b[p->s_b] < p->a[p->s_a]
		&& p->b[p->s_b] > p->a[0])
	{
		return(i);
	}		
	else if (p->b[p->s_b] < *min)
	{
		while (p->a[p->s_a - i] != *min)
			i++;
		*min = p->b[p->s_b];
		return(i);
	}
	while (!(p->b[p->s_b] > p->a[p->s_a - i] 
		&& p->b[p->s_b] < p->a[p->s_a - i - 1]))
	{
		i++;
	}	
	return(i + 1);
}
void	chunks(t_pile *p)
{
	int	min;
	int	max;

	min = 0;
	max = p->s_a / 2 - 1;
	while (p->s_a >= 3)
	{
		if (p->s_b == max)
		{
			min = max;
			max *= 2;
		}
		while (!(p->a[p->s_a] >= min && p->a[p->s_a] <= max))
			ra(p);
		pb(p);
		if (p->b[p->s_b] < max / 2 
			&& !(p->a[p->s_a] >= min && p->a[p->s_a] <= max))
			rr(p);
		if (p->b[p->s_b] < max / 2)
			rb(p);
		
	}
}

void	sort_left(t_pile *p, int i)
{
	int	move;
	int	min;

	min = p->a[p->s_a];
	move = 0;
	while (p->s_b >= 0)
	{
		move = scan_pile(p, &min);
		// printf("move:%d\n psa:%d", move, p->s_a / 2);
		if (move <= p->s_a / 2)
		{
			while (move)
			{
				ra(p);
				move--;
			}
		}
		else
		{
			move = p->s_a - move + 1;
			while (move)
			{
				rra(p);
				move--;
			}
		}
		pa(p);
	}
}

void	tri_100(t_pile *p)
{
	int	i;

	i = 0;
	chunks(p);
	if (check_p(p) == 0)
		tri_3(p);
		// print_pile(p);
	sort_left(p, i);
}

void	tri_500(t_pile *p)
{
	int	i;

	i = 0;
	chunks(p);
	sort_left(p, i);
}