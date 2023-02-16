/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:18:19 by adugain           #+#    #+#             */
/*   Updated: 2023/02/16 17:28:11 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < p->s_a || j < p->s_b)
	{
		if (i < p->s_a)
		{
			ft_printf("%d |", p->a[i]);
			i++;
		}
		else
			ft_printf(" | ");
		if (j < p->s_b)
		{
			printf("%d\n", p->b[j]);
			j++;
		}
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
	if (!(p = malloc(sizeof(t_pile * ))))
		return (free(p), NULL);
	ft_bzero(p, sizeof(t_pile));
	p->s_a = ac - 1;
	p->s_b = 0;
	if (!(p->a = malloc(sizeof(int) * (ac - 1))))
		return (free(p->a), NULL);
	if (!(p->b = malloc(sizeof(int) * (ac - 1))))
		return (free(p->b), free(p->a), NULL);
	while (i < p->s_a)
		p->a[i++] = ft_atoi(av[i + 1]);
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
	sleep(1);
	// tri_5(p);
	pb(p);
	//tri_100(p);
	//last_check(p);
	print_pile(p);
	free(p->a);
	free(p->b);
	return (0);
}