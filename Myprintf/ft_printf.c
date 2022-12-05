/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:06:49 by adugain           #+#    #+#             */
/*   Updated: 2022/12/05 18:22:03 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void    ft_putnbr_base(long int nbr, char *base, int *len)
{
	int	i;
	
	i = 0;
	while (base[i])
		i++;
        if (nbr < 0)
        {
            ft_putchar('-', len);
            nbr = -nbr;
        }
        if (nbr / i)
            ft_putnbr_base(nbr / i, base, len);
        ft_putchar(base[nbr % i], len);
}

void	ft_putstr(char *str, int *len)
{
	int	i;
	
	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i])
	{
		*len += write(1, &str[i], 1);
		i++;
	}
}

void    ft_putptr(unsigned long int nbr, char *base, int *len, int token)
{
	int	i;
	
	i = 0;
	if (!nbr)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	if (token == 1)
		ft_putstr("0x", len);
	while (base[i])
		i++;
        if (nbr / i)
            ft_putptr(nbr / i, base, len, 0);
        ft_putchar(base[nbr % i], len);
}

int	format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		ft_putchar(va_arg(args, int), &len);
	if (c == 's')
		ft_putstr(va_arg(args, char *), &len);
	if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", &len);
	if (c == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", &len);
	if (c == 'x')
		ft_putnbr_base(va_arg(args, long int), "0123456789abcdef", &len);
	if (c == 'X')
		ft_putnbr_base(va_arg(args, long int), "0123456789ABCDEF", &len);
	if (c == 'p')
		ft_putptr(va_arg(args, unsigned long int), "0123456789abcdef", &len, 1);
	if (c == '%')
		ft_putchar('%', &len);
	else
		return (len = -1);
	return(len);
}


int	ft_printf(const char *str, ...)
{
	int	i;
	int	len;
	va_list args;
	
	i = 0;
	len = 0;
	va_start(args, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			len += format(str[i + 1], args);
			if (format(str[i + 1], args) == -1)
				return (-1);
			i++;
		}
		else
			len += write(1, &str[i], 1);	
		i++;
	}
	va_end(args);
	return (len);
}

int main()
{
	char *str = NULL;
	
	printf("%d\n", ft_printf("retour de % "));
	printf("%d\n", printf("retour de % "));
	return(0);
}