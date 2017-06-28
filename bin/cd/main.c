/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:46:40 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/28 02:47:13 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

static void		ft_init_opt(t_opt *opts)
{
	opts->p = 0;
	opts->l = 1;
	opts->start = 1;
}

static t_opt	*ft_active_opt(char opt, t_opt *opts)
{
	if (opt == '-')
	{
		opts->p = 1;
		opts->l = 0;
		opts->lastop = 1;
	}
	else if (opt == 'P')
	{
		opts->p = 1;
		opts->l = 0;
	}
	else if (opt == 'L')
	{
		opts->p = 0;
		opts->l = 1;
	}
	else
		return (NULL);
	return (opts);
}

static t_opt 	*ft_get_cd_opt(char **argv)
{
	size_t		i;
	size_t		j;
	t_opt		*options;

	i = 0;
	if (!(options = (t_opt *)ft_memalloc(sizeof(t_opt))))
		return (NULL);
	ft_init_opt(options);
	while (argv[++i] && argv[i][0] == '-')
	{
		j = 0;
		if (argv[i][1] == 0)
			options->oldp = 1;
		while (argv[i][++j] != 0)
			if (!ft_active_opt(argv[i][j], options))
				return (options);
		options->start++;
		if (options->oldp || options->lastop)
		{
			ft_putendl("lool");
			return (options);
		}
	}
	return (options);
}

int				main(int argc, char **argv, char **env)
{
	char		*working_path;
	char		*destpath;
	char		err;
	t_opt		*options;

	working_path = NULL;
	working_path = getcwd(working_path, 256);
	options = ft_get_cd_opt(argv);
	if (options->oldp)
	{
		destpath = ft_getenv_var("OLDPWD", env);
		ft_putendl(destpath);
	}
	else
		destpath = ft_fill_destpath(argv[options->start], env);
	if ((err = cd_step1(destpath)))
		return (ft_cd_errors(err, destpath));
	else if (destpath[0] == '/')
		return (cd_step7(destpath, env, *options));
	else if (ft_strcmp(destpath, ".") && ft_strcmp(destpath, ".."))
		return (cd_step5(destpath, env, *options));
	return (0);
}
