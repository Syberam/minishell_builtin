/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:28:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 04:36:44 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_putprompt(char *pwd, char **env)
{
	char	*user;

	if (!(user = ft_getenv_var("LOGNAME", env)))
		user = "User unknow";
	ft_putstr("\033[35m");
	ft_putstr(user);
	ft_putstr(" \033[32m");
	ft_putstr(ft_strrchr(pwd, '/') + 1);
	ft_putstr(" $> ");
	ft_putstr("\033[0m");
}
