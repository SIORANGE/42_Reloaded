/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 00:12:58 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 19:14:59 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int index;
	unsigned int jndex;

	index = 0;
	while (dst[index] && index < dstsize)
		index++;
	jndex = 0;
	while (index + jndex + 1 < dstsize && src[jndex])
	{
		dst[index + jndex] = src[jndex];
		jndex++;
	}
	if (index != dstsize)
		dst[index + jndex] = '\0';
	while (src[jndex])
		jndex++;
	return (index + jndex);
}
