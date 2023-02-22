/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:50:39 by adugain           #+#    #+#             */
/*   Updated: 2023/02/22 12:20:20 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_pile **pile_a, t_pile **pile_b, int size_pile)
{
	if (size_pile == 2 && !check_pile(*pile_a))
		sa(pile_a);
	else if (size_pile == 3)
		small_sort(pile_a);
	else if (size_pile > 3 && !check_pile(*pile_a))
		big_sort(pile_a, pile_b);
	
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int	size_pile;
	
	if (ac <= 1)
		return (0);
	if (is_valid_input(av) != 1)
		return(0, ft_printf("wrong input\n"));
	pile_b = NULL;
	ft_printf("filling piles...\n");
	pile_a = fill_pile(ac, av);
	ft_printf("done\n");
	size_pile = get_size(pile_a);
	ft_printf("pile size:%d\n", size_pile);
	ft_printf("indexing...\n");
	pile_index(pile_a, size_pile + 1);
	ft_printf("all running good\n");
	print_pile(pile_a);
	push_swap(&pile_a, &pile_b, size_pile);
	ft_printf("pile a\n");
	print_pile(pile_a);
	ft_printf("pile b\n");
	print_pile(pile_b);
	ft_printf("sorted:%d\n", check_pile(pile_a));
	ft_printf("freeing pile a\n");
	free_piles(&pile_a);
	free_piles(&pile_b);
	return (0);
}