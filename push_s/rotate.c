/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:58:15 by adugain           #+#    #+#             */
/*   Updated: 2023/02/08 16:59:38 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ra(t_pile *p)
{
	int	save;
	int	i;
	
	i = p->s_a + 1;
	save = p->a[p->s_a];
	while (i >= 0)
	{
		p->a[i--] = p->a[i - 1];
	}
	p->a[0] = save;
	ft_printf("ra\n");
}

void	rb(t_pile *p)
{
	int	save;
	int	i;
	
	i = p->s_b + 1;
	save = p->b[p->s_b];
	while (i >= 0)
	{
		p->b[i--] = p->b[i - 1];
	}
	p->b[0] = save;
	ft_printf("rb\n");
}

void	rr(t_pile *p)
{
	ra(p);
	rb(p);
	ft_printf("rr\n");
}