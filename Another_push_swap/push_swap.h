/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:41:48 by adugain           #+#    #+#             */
/*   Updated: 2023/02/20 14:32:04 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_pile
{
	int	val;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
	struct s_pile *next;
}	t_pile;

int	main(int ac, char **av);
int	is_valid_input(char **av);
int	is_digit(char c);
int	is_sign(char c);
int	strnb_comp(char *s1, char *s2);
t_pile	*fill_pile(int ac, char **av);
int	get_size(t_pile *pile);
void	pile_index(t_pile *pile_a, int size_pile);
int	ft_atoi(const char *str);
t_pile	*pile_new(int nb);
void	add_pile_last(t_pile **pile, t_pile *new);
t_pile	*pile_last(t_pile *pile);
t_pile	*pile_before_last(t_pile *pile);

#endif