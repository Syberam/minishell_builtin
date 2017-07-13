/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:31:15 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 11:14:06 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env	*ft_unsetenv(const char *name, t_env *env)
{
	t_env	*current;

	if (!name)
		return (env);
	current = env;
	while (current)
	{
		if (value_poz((char *)name) == value_poz(current->var))
		{
			if (!ft_strncmp(name, current->var, value_poz((char *)name)))
			{
				if (current->prev)
					current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;
				ft_bzero(current->var, ft_strlen(current->var));
				ft_memdel(((void **)&current->var));
				ft_memset(current, 0, sizeof(current));
				ft_memdel((void **)&current);
				return (env);
			}
		}
		current = current->next;
	}
	return (env);
}

void	ft_vars_to_unset(char **names, t_env *env)
{
	size_t	i;

	i = 0;
	while (names[++i])
		ft_unsetenv((const char*)names[i], env);
}
