/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:05:26 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/14 16:06:20 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <dirent.h>

#define	BUFF_SIZE 32

char **Data;

int		get_next_line(const int fd, char **line);
size_t  dataLen(char **str);
int checkStr(char **str);
int check(char **str);
int forking(char *str, char **arg);
int ft_echo(char **str);
char *Get_path(char *str);
int compare(char *str1, char *str2);
void cd(char *new_path);
void pwd();
void env_setup(char *str, char *envval);
#endif
