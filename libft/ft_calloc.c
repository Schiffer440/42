/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:54:41 by adugain           #+#    #+#             */
/*   Updated: 2022/11/14 14:54:43 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size > 0 && nmemb * size / size != nmemb)
		return (0);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}
