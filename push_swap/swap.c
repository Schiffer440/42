/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:21:45 by adugain           #+#    #+#             */
/*   Updated: 2023/02/16 15:11:57 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	sa(t_pile *p)
{
	int save;
	
	save = p->a[p->s_a];
	p->a[p->s_a] = p->a[p->s_a - 1];
	p->a[p->s_a - 1] = save;
	ft_printf("sa\n");
}

void	sb(t_pile *p)
{
	int save;
	
	save = p->b[p->s_b];
	p->b[p->s_b] = p->b[p->s_b - 1];
	p->b[p->s_b - 1] = save;
	ft_printf("sb\n");
}

void	ss(t_pile *p)
{
	sa(p);
	sb(p);
	ft_printf("ss\n");
}