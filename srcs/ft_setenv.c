/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:29:14 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/07 04:34:15 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		set_newvar(char *newvar, t_env *env)
{
	t_env	*new;

	new = (t_env *)ft_memalloc(sizeof(t_env));
	new->var = ft_strdup(newvar);
	while (env->next)
	{
		new->prev = env->prev->next;
		env->prev->next = new;
		env->prev = new;
		new->next = env;
	}
}

char		*var_name(char *varpath)
{
	char	*var_value;
	char	*var_name;

	if (!(var_value = ft_strchr(varpath, '=')))
		return (NULL);
	var_name = ft_strsub(varpath, 0, ft_strlen(varpath) - ft_strlen(var_value));
	return (var_name);
}

size_t		ft_envlen(t_env *env)
{
	size_t	len;

	len = 0;
	while (env)
	{
		env = env->next;
		len++;
	}
	return (len - 1);
}

t_env	*ft_setenv(char *new, t_env *env, int overwrite)
{
	t_env	*current;

	current = env;
	if (!ft_strchr(new, '='))
		return (env);
	while (current)
	{
		if (!ft_strcmp(var_name(new), var_name(env->var)))
		{
			if (!overwrite)
			{
				free(env->var);
				env->var = ft_strdup(new);
			};
			return (env);
		}
		current = current->next;
	}
	set_newvar(new, env);
	return (env);
}
