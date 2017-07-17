/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:28:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 07:38:40 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_putprompt(t_env *env)
{
	static t_env *env_cpy = NULL;
	char	*user;
	char	*pwd;

	if (!env_cpy)
		env_cpy = env;
	pwd = ft_getenv_var("PWD", env_cpy) ? ft_getenv_var("PWD", env_cpy) : ".";
	if (!(user = ft_getenv_var("LOGNAME", env_cpy)))
		user = "User unknow";
	ft_putstr("\033[35m");
	ft_putstr(user);
	ft_putstr(" \033[32m");
	if (ft_getenv_var("HOME", env_cpy))
		if (!(ft_strcmp(pwd, ft_getenv_var("HOME", env_cpy))))
			ft_putstr("(~) ");
	ft_strlen(pwd) == 1 ? ft_putstr(pwd) : ft_putstr(ft_strrchr(pwd, '/') + 1);
	ft_putstr(" $> ");
	ft_putstr("\033[0m");
}
