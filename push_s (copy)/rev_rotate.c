/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:04:33 by adugain           #+#    #+#             */
/*   Updated: 2023/02/08 16:59:38 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	rra(t_pile *p)
{
	int	save;
	int	i;
	
	i = -1;
	save = p->a[0];
	while (++i <= p->s_a)
	{
		p->a[i] = p->a[i + 1];
	}
	p->a[p->s_a] = save;
	ft_printf("rra\n");
}

void	rrb(t_pile *p)
{
	int	save;
	int	i;
	
	i = -1;
	save = p->b[0];
	while (++i <= p->s_b)
	{
		p->b[i] = p->b[i + 1];
	}
	p->b[p->s_b] = save;
	ft_printf("rrb\n");
}

void	rrr(t_pile *p)
{
	rra(p);
	rrb(p);
	ft_printf("rrr\n");
}