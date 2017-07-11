/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:28:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 06:12:29 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_putprompt(t_env *env)
{
	char	*user;
	char	*pwd;

	pwd = ft_getenv_var("PWD", env);
	if (!(user = ft_getenv_var("LOGNAME", env)))
		user = "User unknow";
	ft_putstr("\033[35m");
	ft_putstr(user);
	ft_putstr(" \033[32m");
	if (ft_getenv_var("HOME", env))
		if (!(ft_strcmp(pwd, ft_getenv_var("HOME", env))))
			ft_putstr("(~) ");
	ft_strlen(pwd) == 1 ? ft_putstr(pwd) : ft_putstr(ft_strrchr(pwd, '/') + 1);
	ft_putstr(" $> ");
	ft_putstr("\033[0m");
}
