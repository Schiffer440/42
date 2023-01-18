/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_struct_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:42:09 by adugain           #+#    #+#             */
/*   Updated: 2023/01/18 16:12:02 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
typedef struct concerts
{
	int	date;
	int	lieu;
} concerts;
void	trip(concerts **t, int last)
{
	int	i;
	int	tmp;
	
	i = 0;
	while (i <= last)
	{
		if (t[0][i].date > t[0][last].date)
		{
			tmp = t[0][last].date;
			t[0][last].date = t[0][i].date;
			t[0][i].date = tmp;
		}
		if (t[0][i].date < t[0][i + 1].date)
		{
			tmp = t[0][i + 1];
			t[0][i + 1] = t[0][i];
			
		}
	}
	
}
void 	tournee(concerts *t, int dates)
{
	t->date = dates;
	t->lieu = 0;
}

int main(int ac, char **av)
{
	concerts	*t;
	int	save;

	save = ac - 1;
	t = malloc(sizeof(concerts) * (ac - 1));
	if (!t)
		return (0);
	if (ac > 1);
	{	while ((ac - 1) >= 1)
		{
			ft_printf("ac:%d\n", ac);
			tournee(&t[ac - 1], ft_atoi(av[ac - 1]));
			ac--;
		}
	}
	ac++;
	trip(&t, save);
	while ((ac - 1) <= save)
	{
		ft_printf("date:%d | lieu:%d\n", t[save].date, t[save].lieu);
		save--;
	}
	return(0);
}

