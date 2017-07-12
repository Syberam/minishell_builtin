/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 08:57:15 by sbonnefo         ###   ########.fr       */
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
		ft_setenv(av[1], env, 1);
	else if (!(ft_strcmp(av[0], "unsetenv")))
		ft_vars_to_unset(av, env);
	else
		ft_doexec(av, env);
}

int				main(int argc, char **argv, char **env)
{
	char		**linesplit;
	char		*pwd;
	char		*line;
	char		*linebis;
	t_env		*envi;

	(void)argv;
	if (!(envi = ft_getenv(env)))
		return (0);
	pwd = ft_getenv_var("PWD", envi);
	line = NULL;
	while (argc)
	{
		signal(SIGINT, ft_handler_father);
		ft_putprompt(envi);
		if (gnl(0, &line))
		{
			linebis = ft_strtrim(line);
			//ft_bzero(line, ft_strlen(line));
			free(line);
			line = linebis;
			linesplit = ft_strsplit(line, ' ');
			if (linesplit && linesplit[0])
			{
				ft_dobin(linesplit, envi);
				free(linesplit);
				linesplit = NULL;
			}
			free(line);
			line = NULL;
		}
		else
			exit(0);
	}
	free(envi);
	return (0);
}
