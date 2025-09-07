/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:02:37 by ravazque          #+#    #+#             */
/*   Updated: 2025/09/07 18:29:21 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lngdst;
	size_t	lngsrc;
	size_t	i;

	lngdst = ft_strlen(dst);
	lngsrc = ft_strlen(src);
	i = 0;
	if (lngdst >= dstsize)
		return (dstsize + lngsrc);
	while (src[i] != '\0' && (lngdst + i) < (dstsize - 1))
	{
		dst[lngdst + i] = src[i];
		i++;
	}
	dst[lngdst + i] = '\0';
	return (lngdst + lngsrc);
}
