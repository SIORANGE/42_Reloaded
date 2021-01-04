/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:06:56 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/04 21:51:31 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>

# define ARG_ERR "error : too many arguments"
# define CURRENT_PATH "./"

typedef struct		s_nodes
{
	time_t				sec;
	long				nsec;
	char				*name;
	struct s_nodes		*next;
	struct s_nodes		*previous;
}					t_nodes;

void				list_printer(t_nodes *list);
int					insert_list_h(t_nodes **list, const char *name);
int					insert_list_s(t_nodes **list, const char *name);
int					make_list(DIR *dir, t_nodes **list);

void				ft_lstadd_back(t_nodes **lst, t_nodes *new);
void				ft_lstadd_previous(t_nodes **lst, t_nodes *new);
void				ft_lstfree(t_nodes **lst);
void				ft_lstfront(t_nodes **lst);
t_nodes				*ft_lstlast(t_nodes *lst);
t_nodes				*ft_lstnew(time_t sec, long nsec, const char *name);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin(char const *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
t_nodes				*ft_which_to_insert(t_nodes *lst, t_nodes new);

#endif
