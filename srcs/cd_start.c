/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 23:48:53 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 11:12:01 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

static void		ft_init_opt(t_opt *opts)
{
	opts->p = 0;
	opts->l = 1;
	opts->start = 1;
}

static t_opt	*ft_active_opt(char opt, t_opt *opts)
{
	if (opt == '-' && opts->lastop)
		opts->start--;
	else if (opt == '-')
	{
		opts->p = 0;
		opts->l = 1;
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

static t_opt	*ft_get_cd_opt(char **argv)
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
		{
			options->oldp = 1;
			options->start++;
			return (options);
		}
		while (argv[i][++j] != 0)
			if (!ft_active_opt(argv[i][j], options))
				return (options);
		options->start++;
		if (options->oldp || options->lastop)
			return (options);
	}
	return (options);
}

void			cd_start(char **argv, t_env *env)
{
	char		*destpath;
	char		err;
	t_opt		*options;

	options = ft_get_cd_opt(argv);
	if (options->oldp)
	{
		if (argv[options->start])
			return (ft_putendl_fd("cd: string not in pwd: -", 2));
		destpath = ft_strdup(ft_getenv_var("OLDPWD", env));
	}
	else
		destpath = ft_strdup(ft_fill_destpath(argv[options->start], env));
	if ((err = cd_step1(destpath, env, options)) < 1)
		return (ft_cd_errors(err, destpath, options));
	ft_memdel((void **)&destpath);
	ft_memset((void *)options, 0, sizeof(t_opt));
	ft_memdel((void **)&options);
}
