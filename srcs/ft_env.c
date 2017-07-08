/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 23:47:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/08 05:49:19 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/minishell.h"

int				ft_manage_env_opt(t_env_opt	*opts)
{
	if (opts->i)
		return (0);
	if (opts->v)
	{
		ft_putendl_fd("env: unsupported option -- v", 2);
		ft_putendl_fd("usage: env [-i] [-P utilpath] [-S string] [-u name]", 2);
		ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
		return (0);
	}
	if (opts->wrg)
	{
		ft_putstr_fd("env: illegal option -- ", 2);
		ft_putchar_fd(opts->wrg, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: env [-i] [-P utilpath] [-S string] [-u name]", 2);
		ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
		return (0);
	}
	return (1);
}

void			env_start(char **argv, t_env *env)
{
	size_t		i;
	t_env_opt	*opts;

	i = 0;
	opts = (t_env_opt *)ft_memalloc(sizeof(t_env_opt));
	if (argv[1] && argv[1][0] == '-')
	{
		while (argv[1][++i])
		{
			if (argv[1][i] == 'i')
				opts->i = 1;
			if (argv[1][i] == 'v')
				opts->v = 1;
			else if (i != 1 || argv[1][i] != '-')
			{
				opts->wrg = argv[1][i];
				break;
			}	
		}
	}
	// SI TROISIEME ARGUMENT l'executer
	if (!ft_manage_env_opt(opts))
		return ;
	while (env)
	{
		if (env->var)
			ft_putendl(env->var);
		env = env->next;
	}
	free(opts);
}
