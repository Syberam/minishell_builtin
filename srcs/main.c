/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/08 07:00:01 by sbonnefo         ###   ########.fr       */
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
	return (envtab);
}

void			ft_doexec(char **av, t_env *env)
{
		pid_t	father;
		char	**envi;

		
		av[0] = ft_strmini(av[0]);
		envi = env_to_strtab(env);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
			if (execve(av[0], av, envi) == -1)
			error_wgcmd(av[0]);
}

void			ft_dobin(char **av, t_env *env)
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
	t_env			*envi;

	i = argc;
	envi = ft_getenv(env);
	pwd = ft_getenv_var("PWD", envi);
	while (42)
	{
		ft_putprompt(envi);
		if (gnl(0, argv))
		{
			if (!(argvsplit = ft_strsplit(argv[0], ' ')))
				continue;
			else if (argvsplit[0])
				ft_dobin(argvsplit, envi);
			free(argvsplit[0]);
			free(argvsplit);
			free(argv[0]);
		}
	}
	free(envi);
	return (0);
}
