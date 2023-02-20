/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:18:19 by adugain           #+#    #+#             */
/*   Updated: 2023/02/16 15:49:52 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile *p)
{
	int	i;
	int	j;
	int	k;
	
	k = p->s_b - 1;
	j = p->s_a - 1;
	i = 1;
	ft_printf("A | B \n");
	while(i <= j || i <= k)
	{	
		if (j >= 1)
			ft_printf("%d | ", p->a[j--]);
		else
			ft_printf(" | ");
		if (k >= 1)
			ft_printf("%d\n", p->b[k--]);
		else
			ft_printf("\n");	
	}
}

t_pile	*init_pile(int ac, char **av)
{
	t_pile	*p;
	int	i;
	
	p = NULL;
	i = 0;
	if (!(p = malloc(sizeof(t_pile))))
		return (free(p), NULL);
	ft_bzero(p, sizeof(t_pile));
	p->s_a = ac - 1;
	p->s_b = 0;
	if (!(p->a = malloc(sizeof(int) * (ac))))
		return (free(p->a), free(p), NULL);
	if (!(p->b = malloc(sizeof(int) * (ac))))
		return (free(p->b), free(p->a), free(p), NULL);
	while (--ac > 0)
		p->a[i++] = ft_atoi(av[ac]);
	return (p);
}

int	main(int ac, char **av)
{
	t_pile	*p;
	if (ac > 1)
	{	
		if(!(init_pile(ac, av)))
			write(2, "error\n", 6);
	}
	p = init_pile(ac, av);
	p->a = ft_index(p);
	print_pile(p);
	//tri_5(p);
	//tri_500(p);
	//print_pile(p);
	return (0);
}