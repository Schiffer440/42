/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:44:29 by adugain           #+#    #+#             */
/*   Updated: 2023/02/16 16:54:39 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_index(t_pile *p)
{
	int	i;
	int	j;
	int	index;
	int	*tmp;
	
	i = p->s_a - 1;
	tmp = malloc(sizeof(int) * (i + 1));
		if (!tmp)
			return (0);
	while (i >= 0)
	{
		index = 1;
		j = p->s_a - 1;
		while (j >= 0)
		{
			if (p->a[i] > p->a[j])
				index++;
			j--;
		}
		tmp[i] = index;
		i--;
	}
	free(p->a);
	return (tmp);
}

int	check_p(t_pile *p)
{
	int	i;

	i = 0;
	while (p->s_a > i)
	{
		if (p->a[i] > p->a[i + 1])
			i++;
		else
			return (i);
	}
	return (1);
}

void	tri_3(t_pile *p)
{
	if (check_p(p) == 1)
		return ;
	if (p->a[0] > p->a[1])
	{
		if (p->a[0] < p->a[p->s_a - 1])
			sa(p);
		else if (p->a[0] > p->a[p->s_a - 1]
			&& p->a[1] < p->a[p->s_a - 1])
			ra(p);
		if (p->a[1] > p->a[p->s_a - 1]
			&& p->a[0] > p->a[p->s_a - 1])
		{
			sa(p);
			rra(p);
		}
	}
	else if (p->a[0] < p->a[1])
	{
		if (p->a[0] > p->a[p->s_a - 1])
			rra(p);
		else if (p->a[0] < p->a[p->s_a - 1])
		{
			sa(p);
			ra(p);
		}
	}
}

void	tri_5(t_pile *p)
{
	pb(p);
	pb(p);
	if (check_p(p) == 0)
		tri_3(p);
	if (p->b[p->s_b] < p->b[1])
		sb(p);
	while (p->s_b != -1 || check_p(p) != 1)
	{
		if (p->a[0] < p->b[0]
			&& p->s_a == 2)
		{
			pa(p);
			ra(p);
		}
		else if (p->a[0] > p->b[0]
			&& p->s_b != -1)
			pa(p);
		else if (p->a[0] > p->a[1])
			ra(p);
		else if (p->a[0] < p->a[1])
			rra(p);
	}
}

void	last_check(t_pile *p)
{
	int	move;
	
	if (check_p(p) != 1)
		move = check_p(p);
	while (move-- >= 0)
	{
		if (move <= p->s_a / 2)
			rra(p);
		else
			ra(p);
	}
}