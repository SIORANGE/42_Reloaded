/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:27:17 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 21:35:17 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

t_nodes		*ft_lstnew(time_t sec, long nsec, const char *name)
{
	t_nodes *new;

	if (!(new = (t_nodes *)malloc(sizeof(t_nodes))))
	{
		return (NULL);
	}
	else
	{
		new->sec = sec;
		new->nsec = nsec;
		new->next = NULL;
		new->previous = NULL;
		if (!(new->name = (char *)malloc(sizeof(char) * (ft_strlen(name) + 1))))
			return (NULL);
		ft_strlcpy(new->name, name, ft_strlen(name) + 1);
	}
	return (new);
}
