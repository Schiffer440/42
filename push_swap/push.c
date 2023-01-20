/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:58:07 by adugain           #+#    #+#             */
/*   Updated: 2023/01/20 17:21:52 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_pile *piles)
{
	piles->stack_b[++piles->size_b] = piles->stack_a[piles->size_a];
	piles->size_a -= 1;
}

void	pa(t_pile *piles)
{
	piles->stack_a[++piles->size_a] = piles->stack_b[piles->size_b];
	piles->size_b -= 1;
}