/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 01:40:51 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/24 04:16:50 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv_var(char *var, char **env)
{
	char	*value;
	char	*tofind;
	int		i;

	i = 0;
	tofind = ft_strjoin(var, "="); //ATTENTION BLOQUER NOMS DE VARIABLE avec un =
	while(env[i])
	{
		if (ft_strstr(env[i], tofind))
		{
			free(tofind);
			return (ft_strchr(env[i], '=') + 1);
		}
		i++;
	}
	free(tofind);
	return (NULL);
}

char		**ft_getenv(char **env)
{
	int		i;
	char	**envbis;

	i = 0;
	while (env[i])
		i++;
	envbis = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		envbis[i] = ft_strdup(env[i]);
		i++;
	}
	envbis[i] = 0;
	return (envbis);
}
