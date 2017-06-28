/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:29:14 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/24 05:39:27 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.c"

size_t		ft_envlen(char **env)
{
	size_t	len;

	len = 0;
	while (env[++len - 1])
		;
	return (len - 1);
}

char		**ft_setenv(char *new, char **env, int overwrite);
{
	char	**new_env;
	size_t	env_len;;
	size_t	i;

	if (overwrite)
		return (env);
	if (!ft_strchr(new, '=')
		return (env);
	env_len = ft_envlen(env);
	new_env = (char **)ft_memalloc(sizeof(char *) * (ft_envlen(env) + 2));
	while ((++i - 1) < env_len)
		new_env[i - 1] = env[i - 1];
	new_env[i] = ft_strdup(new);
	new_env[++i] = 0;
	free(env);
	return (new_env)
}
