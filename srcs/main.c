/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 23:46:04 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_doexec(char **av, char **env)
{
		pid_t	father;

		av[0] = ft_strmini(av[0]);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
			if (execve(av[0], av, env) == -1)
				error_wgcmd(av[0]);
}

void			ft_dobin(char **av, char **env)
{
	int			ac;

	ac = 0;
	while (av[++ac - 1])
		;
	if (!(ft_strcmp(av[0], "exit")))
		exit (0);
	else if (!(ft_strcmp(av[0], "echo")))
		echo_start(ac, av, env);
	else if (!(ft_strcmp(av[0], "cd")))
		cd_start(av, env);
	else if (!(ft_strcmp(av[0], "env")))
		env_start(av, env);
	else if (!(ft_strcmp(av[0], "pwd")))
		ft_putendl(getcwd(av[0], 255));
	else
		ft_doexec(av, env);
/*	if (!(ft_strcmp(av[0], "setenv")))
		ft_binsetenv(av, env);
	if (!(ft_strcmp(av[0], "unsetenv")))
		ft_binunsetenv(av, env);i
*/
}


int					main(int argc, char **argv, char **env)
{
	char			**argvsplit;
	char			*pwd;
	int				i;
	t_env			envi;

	i = argc;
	pwd = ft_getenv_var("PWD", env);
	envi = ft_getenv(env);
	while (42)
	{
		ft_putprompt(pwd, env);
		if (gnl(0, argv))
		{
			if (!(argvsplit = ft_strsplit(argv[0], ' ')))
				continue;
			else if (argvsplit[0])
				ft_dobin(argvsplit, env);
		}
	}
	return (0);
}
