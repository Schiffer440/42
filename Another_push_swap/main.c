/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:50:39 by adugain           #+#    #+#             */
/*   Updated: 2023/02/20 14:51:44 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int	size_pile;
	
	if (ac < 2)
		return (0);
	if (is_valid_input(av) != 1)
		return(0, printf("wrong input\n"));
	pile_b = NULL;
	pile_a = fill_pile(ac, av);
	size_pile = get_size(pile_a);
	pile_index(pile_a, size_pile);
	printf("running good\n");
	return (0);
}