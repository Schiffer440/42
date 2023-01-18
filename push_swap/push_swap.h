/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:09:26 by adugain           #+#    #+#             */
/*   Updated: 2023/01/16 15:48:39 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	struct s_pile	*prec;
	int	nb;
	int	pos;
	struct s_pile	*next;
} t_pile;

int	ft_atoi(const char *str);
int	ft_printf(const char *str, ...);
int	format(char c, va_list args);

#endif