/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:09:26 by adugain           #+#    #+#             */
/*   Updated: 2023/02/08 16:59:38 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define bool unsigned int
# define true 1
# define false 0

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_pile
{
	int	s_a;
	int	*a;
	int	s_b;
	int	*b;
} t_pile;

int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int	format(char c, va_list args);
void	ft_bzero(void *s, size_t n);
void	pa(t_pile *p);
void	pb(t_pile *p);
void	sa(t_pile *p);
void	sb(t_pile *p);
void	ss(t_pile *p);
void	ra(t_pile *p);
void	rb(t_pile *p);
void	rr(t_pile *p);
void	rra(t_pile *p);
void	rrb(t_pile *p);
void	rrr(t_pile *p);
void	tri_3(t_pile *p);
int	check_p(t_pile *p);
void tri_5(t_pile *p);
int	*ft_index(t_pile *p);
void	print_pile(t_pile *p);
void	tri_100(t_pile *p);
void	chunks(t_pile *p);
void	sort_left(t_pile *p, int i);
void	tri_500(t_pile *p);


#endif