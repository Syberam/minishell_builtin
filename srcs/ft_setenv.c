/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:29:14 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/17 21:39:48 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		set_newvar(char *newvar, t_env *env)
{
	t_env		*new;

	new = (t_env *)ft_memalloc(sizeof(t_env));
	new->var = newvar;
	while (env->next)
		env = env->next;
	env->next = new;
	new->prev = env;
}

size_t			value_poz(char *varline)
{
	size_t		i;

	i = 0;
	while (varline[i] && varline[i] != '=')
		i++;
	return (i);
}

size_t			ft_envlen(t_env *env)
{
	size_t		len;

	len = 0;
	while (env)
	{
		env = env->next;
		len++;
	}
	return (len - 1);
}

t_env			*ft_setenv(char *new, t_env *env)
{
	t_env		*current;

	if (!new)
		return (env);
	if (!ft_strchr(new, '='))
		return (env);
	current = env;
	while (current)
	{
		if (value_poz(new) == value_poz(current->var))
			if (!ft_strncmp(new, current->var, value_poz(new)))
			{
				ft_memdel((void **)&current->var);
				current->var = new;
				return (env);
			}
		current = current->next;
	}
	set_newvar(new, env);
	return (env);
}
