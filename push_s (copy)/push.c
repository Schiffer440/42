/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:58:07 by adugain           #+#    #+#             */
/*   Updated: 2023/02/16 16:25:20 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_pile *p)
{
	int	i;
	
	i = 0;
	while (i <= p->s_b - 1)
	{
		p->b[p->s_b - i] = p->b[p->s_b - 1 - i];
		i++;
	}
	p->b[0] = p->a[0];
	i = 0;
	while (i <= p->s_a - 2)
	{
		p->a[i] = p->a[i + 1];
		i++;
	}
	p->s_b += 1;
	p->s_a -= 1;
	ft_printf("pb\n");
}

void	pa(t_pile *p)
{
	p->a[++p->s_a] = p->b[p->s_b];
	p->s_b -= 1;
	ft_printf("pa\n");
}