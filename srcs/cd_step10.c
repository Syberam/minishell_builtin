/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:05:50 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/07 07:50:29 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cd.h"

char			cd_step10(char *destpath, t_env *env, t_opt *options)
{
	char		*pwd;
	t_env		*forgcc;

	forgcc = env;
	pwd = NULL;
	pwd = getcwd(pwd, 255);
	if ((chdir(destpath)) == -1)
		return (CD_CHDIR_FAILURE);
	while (env)
	{
		if (!ft_strncmp(env->var, "OLDPWD=", 7))
		{
			free(env->var);
			env->var = ft_strjoin("OLDPWD=", pwd);
		}
		else if (!ft_strncmp(env->var, "PWD=", 4))
		{
			free(env->var);
			env->var = ft_strjoin("PWD=", destpath);
		}
		env = env->next;
	}
	if (!options->p)
		return (0);
	return (0);
}
