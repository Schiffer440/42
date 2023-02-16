/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:24 by adugain           #+#    #+#             */
/*   Updated: 2023/02/16 13:59:10 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_pile(t_pile *p, int pos_b)
{
	int	i;

	i = 0;
	if (pos_b < p->min)
	{
		printf("check1\n");
		while (p->a[i] != p->min)
			i++;
		return (i);
	}
	else if (pos_b < p->a[p->s_a] && pos_b > p->a[0])
	{
		printf("check2\n");
		return(0);
	}
	while (!(pos_b < p->a[i] && pos_b > p->a[i + 1]))
	{
		printf("check3\n");
		i++;
	}	
	return (i + 1);
}

void	chunks(t_pile *p)
{
	int	min;
	int	max;

	min = 0;
	max = p->s_a / 2 - 1;
	while (p->s_a >= 3)
	{
		// sleep(1);
		// print_pile(p);
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

void	sort_left(t_pile *p)
{
	int	i;
	int	pos;
	move	best;
	move	comp;
	
	i = 0;
	init_move(&comp, 0);
	while (p->s_b - i != -1)
	{
		if (i < p->s_b / 2)
			comp.rb = i;
		else
			comp.rrb = p->s_b + 1 - i;
		pos = scan_pile(p, p->b[p->s_b - i]);
		printf("pos%d\n", pos);
		if (pos > p->s_a / 2)
			comp.ra = p->s_a + 1 - pos;
		else
			comp.rra = pos;
		printf("b[i]%d\nra%d\nrb%d\nrra%d\nrrb%d\ntot%d\n", p->b[p->s_b - i], comp.ra, comp.rb, comp.rra, comp.rrb, comp.total);
		i++;
	}
	pa(p);
}

void	tri_100(t_pile *p)
{
	chunks(p);
	if (check_p(p) == 1)
		tri_3(p);
	pa(p);
	print_pile(p);	
	p->min = p->a[p->s_a];
	sort_left(p);
}

void	tri_500(t_pile *p)
{
	chunks(p);
	sort_left(p);
}