/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:09:26 by adugain           #+#    #+#             */
/*   Updated: 2023/01/20 18:14:24 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_pile
{
	int	size_a;
	int	*stack_a;
	int	size_b;
	int	*stack_b;
} t_pile;

int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int	format(char c, va_list args);
void	ft_bzero(void *s, size_t n);
void	pa(t_pile *piles);
void	pb(t_pile *piles);
void	sa(t_pile *piles);
void	sb(t_pile *piles);
void	ss(t_pile *piles);
void	ra(t_pile *piles);
void	rb(t_pile *piles);
void	rr(t_pile *piles);
void	rra(t_pile *piles);
void	rrb(t_pile *piles);
void	rrr(t_pile *piles);


#endif