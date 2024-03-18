/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkhwana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:20:55 by tmkhwana          #+#    #+#             */
/*   Updated: 2020/03/05 14:35:09 by tmkhwana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# define FLAGS "alrSt"
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include "libft/libft.h"

typedef struct			s_file_info
{
	char				*rwx;
	int					links;
	char				*user;
	char				*group;
	int					b_size;
	char				*time;
	char				*file_name;
	char				*full_name;
	struct s_file_info	*next;
}						t_file_info;

typedef struct			s_file_list
{
	char				*file;
	char				*path;
	struct s_file_list	*next;
}						t_file_list;

typedef	struct			s_head
{
	t_file_info			*l_head;
}						t_head;

char            *get_rwx(struct stat sb);
char        	*valid_flags(char *av, int j);
int				getMaxLen(t_file_list *files, char *col, int main);
void        	free_file_list(t_file_list *file_head, int path);
void        	free_info(t_file_info *file_head);
void			get_flags(char **line, char **av, int i, int g);
void    		long_print(t_file_info *file, int s_size, int s_link);
void			print_pad(char *str, int str_len, int max_len);
void        	print_folders(t_file_list *files, char *flags, t_file_list *file);
void        	print_error(char *err_file);
void        	print_r_files(char *filename, char *flags, char *path, int s, int l);
void        	printTotal(t_file_list *files, char *dir_name);
void        	start_f_print(t_file_list *files, char *flags, int size);
void        	start_print(t_file_list *files, char *flags);
t_file_info     *collect_info(t_file_info *file, char *name, char *path);
t_file_info    	*get_dir_files(char *path);
t_file_list     *asc_file_sort(t_file_list *files);
t_file_list     *time_file_sort(t_file_list *files);
t_file_list     *collect_files(char **av, int i, t_file_list *head, struct stat *sb);
t_file_list     *desc_file_sort(t_file_list *files);
t_file_list     *dir_files(char *path, char *fpath, struct stat sb, char *flags,char *full_path);
t_file_list     *msize_file_sort(t_file_list *files);
t_file_list     *rm_size_file_sort(t_file_list *files);
t_file_list     *rm_time_file_sort(t_file_list *files);
t_file_list     *rtime_file_sort(t_file_list *files);
t_file_list     *m_time_file_sort(t_file_list *files);
t_file_list     *rsize_file_sort(t_file_list *files);
t_file_list     *swap(t_file_list *curr);
t_file_list     *size_file_sort(t_file_list *files);
t_file_list     *sort_file_list(t_file_list *files, char *flags, int main);

#endif