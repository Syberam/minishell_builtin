/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/18 02:28:02 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char			**env_to_strtab(t_env *env)
{
	size_t	len;
	char	**envtab;
	int		i;

	len = ft_envlen(env);
	envtab = (char **)ft_memalloc(sizeof(char *) * (len + 1));
	i = 0;
	while (env)
	{
		envtab[i] = env->var;
		i++;
		env = env->next;
	}
	envtab[i] = 0;
	return (envtab);
}

void			ft_dobin(char **av, t_env *env)
{
	av[0] = ft_strmini(av[0]);
	if (!(ft_strcmp(av[0], "exit")))
		exit(0);
	else if (!(ft_strcmp(av[0], "echo")))
		echo_start(av, env);
	else if (!(ft_strcmp(av[0], "cd")))
		cd_start(av, env);
	else if (!(ft_strcmp(av[0], "env")))
		env_start(av, env);
	else if (!(ft_strcmp(av[0], "pwd")))
		ft_putendl(ft_getenv_var("PWD", env));
	else if (!(ft_strcmp(av[0], "setenv")))
		ft_setenv(ft_strdup(av[1]), env);
	else if (!(ft_strcmp(av[0], "unsetenv")))
		ft_vars_to_unset(av, env);
	else if (!(ft_strchr(av[0], '/')))
		exec_direct_bin(av, env);
	else
		ft_doexec(av, env);
	ft_setenv(ft_ext_strjoin_free("_=", av[0], 0), env);
}

int				main(int argc, char **argv, char **env)
{
	char		*line;
	char		*linebis;
	t_env		*envi;

	envi = ft_getenv(env);
	line = NULL;
	while (argc)
	{
		signal(SIGINT, ft_handler_father);
		ft_putprompt(envi);
		if (gnl(0, &line) == 1)
		{
			linebis = ft_strtrim(line);
			ft_memdel((void **)&line);
			line = linebis;
			argv = ft_strsplit(line, ' ');
			if (argv && argv[0])
				ft_dobin(argv, envi);
			ft_freetab(argv);
			ft_memdel((void **)&line);
		}
		else
			exit(0);
	}
	return (0);
}
