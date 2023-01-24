/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:18:19 by adugain           #+#    #+#             */
/*   Updated: 2023/01/24 17:35:26 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile *piles)
{
	int	i;
	int	j;
	int	k;
	
	k = piles->size_b;
	j = piles->size_a;
	i = 0;
	ft_printf("A | B \n");
	while(i <= j || i <= k)
	{	
		if (j >= 0)
			ft_printf("%d | ", piles->stack_a[j--]);
		else
			ft_printf(" | ");
		if (k >= 0)
			ft_printf("%d\n", piles->stack_b[k--]);
		else
			ft_printf("\n");	
	}
}

t_pile	*init_pile(int ac, char **av)
{
	t_pile	*piles;
	int	i;
	
	piles = NULL;
	i = 0;
	if (!(piles = malloc(sizeof(t_pile))))
		return (free(piles), NULL);
	ft_bzero(piles, sizeof(t_pile));
	piles->size_a = ac - 2;
	piles->size_b = -1;
	if (!(piles->stack_a = malloc(sizeof(int) * (ac - 1))))
		return (free(piles->stack_a), free(piles), NULL);
	if (!(piles->stack_b = malloc(sizeof(int) * (ac - 1))))
		return (free(piles->stack_b), free(piles->stack_a), free(piles), NULL);
	while (--ac > 0)
		piles->stack_a[i++] = ft_atoi(av[ac]);
	return (piles);
}

int	main(int ac, char **av)
{
	t_pile	*piles;
	if (ac > 1)
	{	
		if(!(init_pile(ac, av)))
			write(2, "error\n", 6);
	}
	piles = init_pile(ac, av);
	piles->stack_a = ft_index(piles);
	print_pile(piles);
	//tri_5(piles);
	tri_100(piles);
	print_pile(piles);
	return (0);
}