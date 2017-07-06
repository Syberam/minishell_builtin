/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 01:40:51 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 23:53:25 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv_var(char *var, t_env *env)
{
	char	*tofind;
	int		i;

	i = 0;
	tofind = ft_strjoin(var, "=");
	while(env)
	{
		if (ft_strstr(env[i], tofind))
		{
			free(tofind);
			return (ft_strchr(env[i], '=') + 1);
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

	i = 0;
	while (env[i])
	{
		prenv = (envbis) ? envbis : NULL;
		envbis = (t_env *)ft_memalloc(sizeof(t_env));
		prenv->next = envbis;
		envbis->prev = prenv;
		envbis->next = NULL;
		envbis->var = ft_strdup(env[i]);
		i++;
	}
	return (envbis);
}
