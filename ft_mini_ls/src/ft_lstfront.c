/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfront.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:16:28 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 21:37:37 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

void		ft_lstfront(t_nodes **lst)
{
	if (!lst)
		return ;
	while ((*lst)->previous != NULL)
	{
		*lst = (*lst)->previous;
	}
}
