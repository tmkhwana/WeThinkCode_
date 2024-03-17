/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:17:42 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/13 13:58:03 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int forking(char *str, char **arg)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(&str[0], arg, Data);
	}
	else if (pid < 0)
		ft_putendl("failed");
	wait(&pid);
	return (1);
}
