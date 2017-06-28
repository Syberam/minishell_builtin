/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/27 18:40:35 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_keepenv(char **env)
{
	int		fd;
	char	**buff;
	size_t	i;
	size_t	j;

	fd = open(".michelenv", O_CREAT | O_WRONLY, S_IRWXU);
/*	close(fd);
	fd = open(".michelenv", O_WRONLY);
*/	i = 0;
	while (env[++i - 1])
	{
		write(fd, env[i - 1], ft_strlen(env[i - 1]) + 1);
		write(fd, "\n", 1);
	}
	close (fd);
}

char		*ft_write_path(char *bin)
{
	char	*path;

	if (!ft_strncmp(bin, "/bin/", 5))
		return (ft_strdup(bin));
	path = ft_strjoin("bin/", bin);
	path = ft_ext_strjoin_free(path, "/", 1);
	path = ft_ext_strjoin_free(path, bin, 1);
	path = ft_ext_strjoin_free(path, ".out", 1);
	return (path);
}

void			ft_dobuiltin(char **av, char **env)
{
		pid_t	father;
		char	*path;

		av[0] = ft_strmini(av[0]);
		path = ft_write_path(av[0]);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
		{
			if (execve(path, av, env) == -1)
				execve("bin/errors/errors.out", av, env);
		}
		ft_bzero((void *)path, ft_strlen(path));
		return (free(path));
}

int					main(int argc, char **argv, char **env)
{
	char			**argvsplit;
	char			*pwd;
	int				i;
	int				fd;

	i = argc;
	pwd = ft_getenv_var("PWD", env);
	ft_keepenv(env);
	env = ft_getenv(env);
	while (42)
	{
		ft_putprompt(pwd, env);
		if ((fd = open(".michelenv", O_RDONLY)) == -1)
			ft_keepenv(env);
		else
			close(fd);
		if (gnl(0, argv))
		{
			if (!(argvsplit = ft_strsplit(argv[0], ' ')))
				continue;
			if (argvsplit[0] && !ft_strcmp(argvsplit[0], "exit"))
				return (0);
			else if (argvsplit[0])
				ft_dobuiltin(argvsplit, env);
		}
	}
	return (0);
}
