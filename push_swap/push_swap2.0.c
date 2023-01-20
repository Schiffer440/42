/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:18:19 by adugain           #+#    #+#             */
/*   Updated: 2023/01/20 14:01:11 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile *piles)
{
	int	i;

	i = 0;
	while(i <= piles->size_a)
	{
		ft_printf("%d\n", piles->stack_a[i]);
		i++;
	}
}

t_pile	*init_pile(int ac, char **av)
{
	t_pile	*piles;
	int	i;
	
	piles = NULL;
	i = 0;
	if (!(piles = malloc(sizeof(t_pile))))
		return (free(l_pile), NULL);
	ft_bzero(piles, sizeof(t_pile));
	piles->size_a = ac - 2;
	piles->size_b = -1;
	if (!(piles->stack_a = malloc(sizeof(int) * ac)))
		return (free(piles->stack_a), free(l_pile), NULL);
	if (!(piles->stack_b = malloc(sizeof(int) * ac)))
		return (free(piles->stack_b), free(piles->stack_a), free(l_pile), NULL);
	while (--ac > 0)
		piles->stack_a[i++] = ft_atoi(av[ac]);
	return (l_pile);
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
	print_pile(piles);
	return (0);
}