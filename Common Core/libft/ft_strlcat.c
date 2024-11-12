/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:24:05 by nbled             #+#    #+#             */
/*   Updated: 2022/07/03 03:21:01 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	len = ft_strlen(dst);
	if (len > size)
		return (ft_strlen(src) + size);
	while (src[i] && (len + i + 1) < size)
	{
		dst[len + i] = src[i];
		i++;
	}
	if (size)
		dst[len + i] = '\0';
	if (len < size)
		return (len + ft_strlen(src));
	return (ft_strlen(src) + size);
}
