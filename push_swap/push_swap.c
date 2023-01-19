/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:33:46 by adugain           #+#    #+#             */
/*   Updated: 2023/01/19 17:32:39 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_pile(t_pile *a, int nb, int i)
{
		a->stack[i] = nb;
}

int main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	int	i;

	i = 0;
	a.size = ac - 2;
	ft_printf("a->size %d\n", a.size);
	b.size = ac - 2;
	ft_printf("b->size %d\n", b.size);
	ft_printf("mallocing a...\n");
	a.stack = malloc(sizeof(int) * (ac - 1));
	if (!a.stack)
		return(0);
	ft_printf("a OK\n");
	ft_printf("mallocing b...\n");
	b.stack = malloc(sizeof(int) * (ac - 1));
	if (!b.stack)
		return (0);
	ft_printf("b OK\n");
	if (ac > 1)
	{
		while ((ac - 1) >= 1)
		{
			ft_printf("stacking %d\n", ft_atoi(av[ac - 1]));
			a.stack[ac - 2] = ft_atoi(av[ac - 1]);
			ft_printf("%d\n", (ac - 2));
			ft_printf("%d\n", a.stack[ac - 2]);
			ac--;
		}
	}
	ft_printf("a->stack[i]:%d\n", a.stack[i]);
	while (a.stack[i] <= a.stack[a.size])
	{
		ft_printf("%d\n", a.stack[i]);
		i++;
	}
	return (0);	
}