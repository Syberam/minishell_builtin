/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:29:14 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/05 20:11:33 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_get_var_name(char *varpath)
{
	char	*var_value;
	char	*var_name;

	if (!(var_value = ft_strchr(varpath, '=')))
		return (NULL);
	var_name = ft_strsub(varpath, 0, ft_strlen(varpath) - ft_strlen(var_value));
	return (var_name);
}

size_t		ft_envlen(char **env)
{
	size_t	len;

	len = 0;
	while (env[++len - 1])
		;
	return (len - 1);
}

char		**ft_setenv(char *new, char **env, int overwrite)
{
	char	**new_env;
	char	*var_name;
	size_t	env_len;
	size_t	i;

	if (overwrite)
		return (env);
	if (!ft_strchr(new, '='))
		return (env);
	env_var = ft_getenv_var(new, env);
	//if (ft_get
	env_len = ft_envlen(env);
	new_env = (char **)ft_memalloc(sizeof(char *) * (ft_envlen(env) + 2));
	while ((++i - 1) < env_len)
		new_env[i - 1] = env[i - 1];
	new_env[i] = ft_strdup(new);
	new_env[++i] = 0;
	free(env);
	return (new_env);
}
