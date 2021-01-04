/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:49:51 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 22:41:58 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_mini_ls.h"

void		list_printer(t_nodes *list)
{
	while (list)
	{
		write(1, list->name, ft_strlen(list->name));
		write(1, "\n", 1);
		list = list->next;
	}
	return ;
}

int			insert_list_h(t_nodes **list, const char *name)
{
	struct stat		info;
	char			*path;
	t_nodes			*new;
	t_nodes			*temp;

	if (!(path = ft_strjoin(CURRENT_PATH, name)))
		return (1);
	if (stat(path, &info) != 0)
		return (1);
	free(path);
	new = ft_lstnew(info.st_mtimespec.tv_sec, info.st_mtimespec.tv_nsec, name);
	if (new == NULL)
		return (1);
	temp = ft_which_to_insert(*list, *new);
	if (!temp)
	{
		ft_lstadd_back(list, new);
		return (0);
	}
	ft_lstadd_previous(&temp, new);
	return (0);
}

int			insert_list_s(t_nodes **list, const char *name)
{
	struct stat		info;
	char			*path;
	t_nodes			*new;
	t_nodes			*temp;

	if (!(path = ft_strjoin(CURRENT_PATH, name)))
		return (1);
	if (lstat(path, &info) != 0)
		return (1);
	free(path);
	new = ft_lstnew(info.st_mtimespec.tv_sec, info.st_mtimespec.tv_nsec, name);
	if (new == NULL)
		return (1);
	temp = ft_which_to_insert(*list, *new);
	if (!temp)
	{
		ft_lstadd_back(list, new);
		return (0);
	}
	ft_lstadd_previous(&temp, new);
	return (0);
}

int			make_list(DIR *dir, t_nodes **list)
{
	struct dirent	*dent;

	errno = 0;
	while ((dent = readdir(dir)) != NULL)
	{
		if (dent->d_name[0] == '.')
			continue;
		if (dent->d_type == DT_LNK)
		{
			if (insert_list_s(list, dent->d_name))
				return (1);
		}
		else
		{
			if (insert_list_h(list, dent->d_name))
				return (1);
		}
		ft_lstfront(list);
		errno = 0;
	}
	closedir(dir);
	if (errno)
		return (1);
	return (0);
}

int			main(int argc, char *argv[])
{
	DIR				*dir;
	t_nodes			*list;
	int				ret;

	if (argc != 1 && argv)
	{
		write(2, ARG_ERR, ft_strlen(ARG_ERR));
		return (1);
	}
	dir = opendir(CURRENT_PATH);
	if (dir == NULL)
	{
		perror("error");
		return (1);
	}
	list = NULL;
	if ((ret = make_list(dir, &list)))
	{
		ft_lstfree(&list);
		perror("error");
		return (1);
	}
	list_printer(list);
	ft_lstfree(&list);
	return (1);
}
