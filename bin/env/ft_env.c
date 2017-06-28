/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 23:47:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/22 05:23:22 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minishell.h"

typedef struct		t_env_opt
{
	char	i;
	char	v;
	char	wrg;
}					t_env_opt;

int				ft_manage_env_opt(t_env_opt	opts)
{
	if (opts.i)
		return (0);
	if (opts.v)
	{
		ft_putendl_fd("env: unsupported option -- v", 2);
		ft_putendl_fd("usage: env [-i] [-P utilpath] [-S string] [-u name]", 2);
		ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
		return (0);
	}
	if (opts.wrg)
	{
		ft_putstr_fd("env: illegal option -- ", 2);
		ft_putchar_fd(opts.wrg, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: env [-i] [-P utilpath] [-S string] [-u name]", 2);
		ft_putendl_fd("           [name=value ...] [utility [argument ...]]", 2);
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv, char **env)
{
	size_t		i;
	t_env_opt	opts;

	i = 0;
	if (argv[1] && argv[1][0] == '-')
	{
		while (argv[1][++i])
		{
			if (argv[1][i] == 'i')
				opts.i = 1;
			if (argv[1][i] == 'v')
				opts.v = 1;
			else if (i != 1 || argv[1][i] != '-')
			{
				opts.wrg = argv[1][i];
				break;
			}	
		}
	}
	if (!ft_manage_env_opt(opts))
		return (0);
	while (env[i])
	{
		if (env[i][0])
			ft_putendl(env[i]);
		i = i + 1;
	}
	return (0);
}
