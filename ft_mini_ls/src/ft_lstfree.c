/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:07:56 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 21:38:22 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

void		ft_lstfree(t_nodes **lst)
{
	t_nodes			*next;

	ft_lstfront(lst);
	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->name);
		free(*lst);
		*lst = next;
	}
	return ;
}
