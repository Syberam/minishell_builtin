/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 01:40:51 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/07 06:12:45 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		ft_set_shlvl(t_env *env)
{
	int		shlvl;
	char	*newshlvl;

	while (env)
	{
		if (!ft_strncmp(env->var, "SHLVL", 5))
		{
			shlvl = ft_atoi(ft_strchr(env->var, '=') + 1);
			newshlvl = ft_ext_strjoin_free("SHLVL=", ft_itoa(shlvl + 1), 2);
			ft_bzero((void *)env->var, (size_t)ft_strlen(env->var));
			free(env->var);
			env->var = newshlvl;
			return ;
		}
	env = env->next;
	}
}

char	*ft_getenv_var(char *var, t_env *env)
{
	char	*tofind;
	int		i;

	i = 0;
	tofind = ft_strjoin(var, "=");
	while (env)
	{
		if (ft_strstr(env->var, tofind))
		{
			free(tofind);
			return (ft_strchr(env->var, '=') + 1);
		}
		env = env->next;
	}
	free(tofind);
	return (NULL);
}

t_env	*ft_getenv(char **env)
{
	int		i;
	t_env	*envbis;
	t_env	*prenv;
	t_env	*start;

	i = 0;
	start = (t_env *)ft_memalloc(sizeof(t_env));
	start->var = ft_strdup(env[i++]);
	prenv = start;
	while (env[i])
	{
		envbis = (t_env *)ft_memalloc(sizeof(t_env));
		envbis->prev = prenv;
		prenv->next = envbis;
		envbis->var = ft_strdup(env[i]);
		prenv = envbis;
		i++;
	}
	ft_set_shlvl(start);
	return (start);
}
