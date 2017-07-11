/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_step10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 00:05:50 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 00:51:43 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

char			cd_step10(char *destpath, t_env *env, t_opt *options)
{
	char		*pwd;

	pwd = NULL;
	pwd = ft_strdup(ft_getenv_var("PWD", env));
	if ((chdir(destpath)) == -1)
		return (CD_CHDIR_FAILURE);
	if (options->oldp)
		ft_putendl(destpath);
	while (env)
	{
		if (!ft_strncmp(env->var, "OLDPWD=", 7))
		{
			free(env->var);
			env->var = ft_ext_strjoin_free("OLDPWD=", pwd, 2);
		}
		else if (!ft_strncmp(env->var, "PWD=", 4))
		{
			free(env->var);
			env->var = ft_strjoin("PWD=", destpath);
		}
		env = env->next;
	}
	return (0);
}
