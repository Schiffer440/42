/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:24:20 by adugain           #+#    #+#             */
/*   Updated: 2022/11/09 16:24:27 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			len1;
	size_t			len2;
	unsigned char	*u1;

	if (size == 0)
		return (ft_strlen(src));
	u1 = (unsigned char *)src;
	i = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size <= len1)
		return (size + len2);
	while (len1 + i < size - 1 && (u1[i] || dst[i]))
	{
		dst[len1 + i] = u1[i];
		i++;
	}
	dst[len1 + i] = '\0';
	return (len1 + len2);
}
