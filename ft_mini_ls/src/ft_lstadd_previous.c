/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_previous.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:02:07 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 21:47:57 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

void		ft_lstadd_previous(t_nodes **lst, t_nodes *new)
{
	t_nodes		*previous_lst;

	new->next = *lst;
	new->previous = (*lst)->previous;
	previous_lst = (*lst)->previous;
	(*lst)->previous = new;
	if (previous_lst != NULL)
		previous_lst->next = new;
	return ;
}
