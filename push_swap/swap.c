/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:21:45 by adugain           #+#    #+#             */
/*   Updated: 2023/01/16 12:57:54 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(int a0, int a1)
{
	int save;
	
	save = a0;
	a0 = a1;
	a1 = save;
}

void	swap_b(int b0, int b1)
{
	int save;
	
	save = b0;
	b0 = b1;
	b1 = save;
}

void	swap_swap(void)
{
	swap_a;
	swap_b;
}