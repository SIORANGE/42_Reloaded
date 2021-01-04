/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_to_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 10:29:13 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/05 00:03:05 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

t_nodes		*ft_which_to_insert(t_nodes *lst, t_nodes new)
{
	if (!lst)
		return (NULL);
	while (lst && (
					lst->sec < new.sec
					|| (lst->sec == new.sec && lst->nsec < new.nsec)
					|| (lst->sec == new.sec && lst->nsec == new.nsec
									&& ft_strcmp(lst->name, new.name) <= 0)))
	{
		lst = lst->next;
	}
	return (lst);
}
