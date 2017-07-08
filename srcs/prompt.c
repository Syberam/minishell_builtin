/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:28:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/08 06:13:49 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_putprompt(t_env *env)
{
	char	*user;
	char	*pwd;

	pwd = ft_getenv_var("PWD", env);
	if (!(ft_strcmp(pwd, ft_getenv_var("HOME", env))))
		pwd = ft_strcat(pwd, " (~)");
	if (!(user = ft_getenv_var("LOGNAME", env)))
		user = "User unknow";
	ft_putstr("\033[35m");
	ft_putstr(user);
	ft_putstr(" \033[32m");
	ft_putstr(ft_strrchr(pwd, '/') + 1);
	ft_putstr(" $> ");
	ft_putstr("\033[0m");
}
