/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:05:50 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 04:31:49 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

char			cd_step10(char *destpath, char **env, t_opt *options)
{
	char		*pwd;
	char		**envbis;

	pwd = NULL;
	pwd = ft_strdup(getcwd(pwd, 255));
	if ((chdir(destpath)) == -1)
		return (CD_CHDIR_FAILURE);
	envbis = env;
/*	while (env)
	{
		if (!ft_strcmp(env->envar, "OLDPWD"))
		{
			free(env->content);
			env->content = pwd;
		}
		else if (!ft_strcmp(env->envar, "PWD"))
		{
			free(env->content);
			env->content = destpath;
		}
		env = env->next;
	}
	while (debbenv)
	{
		ft_putstr(debbenv->envar);
		ft_putstr("=");
		ft_putendl(debbenv->content);
		debbenv = debbenv->next;
	}*/
	if (!options->p)
		return (0);
	return (0);
}
