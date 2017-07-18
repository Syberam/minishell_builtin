/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:16:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/18 02:30:25 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			exec_direct_bin(char **av, t_env *env)
{
	t_stat		fstat;

	if ((lstat(av[0], &fstat)) == -1)
	{
		ft_putstr_fd("MiniShell: no such file or directory: ", 2);
		return (ft_putendl_fd(av[0], 2));
	}
	if (S_ISDIR(fstat.st_mode))
	{
		ft_putstr_fd("MiniShell: ", 2);
		ft_putstr_fd(av[0], 2);
		return (ft_putstr_fd(": is a directory: ", 2));
	}
	if ((fstat.st_mode & S_IXUSR) != S_IXUSR)
	{
		ft_putstr_fd("MiniShell: permission denied :", 2);
		return (ft_putstr_fd(av[0], 2));
	}
	ft_doexec(av, env);
}

void			ft_exec_path(char **av, t_env *env)
{
	char	**paths;
	int		i;
	t_stat	pstat;

	i = -1;
	paths = ft_strsplit(ft_getenv_var("PATH", env), ':');
	while (paths[++i])
	{
		paths[i] = ft_ext_strjoin_free(paths[i], "/", 1);
		paths[i] = ft_ext_strjoin_free(paths[i], av[0], 1);
		if ((lstat(paths[i], &pstat) != -1) && !S_ISDIR(pstat.st_mode))
		{
			ft_memdel((void **)&av[0]);
			av[0] = ft_strdup(paths[i]);
			ft_freetab(paths);
			return (ft_doexec(av, env));
		}
	}
	ft_freetab(paths);
	ft_putstr_fd("MiniShell: Command not found: ", 2);
	ft_putendl_fd(av[0], 2);
}

void			ft_doexec(char **av, t_env *env)
{
	pid_t	father;
	char	**envi;
	int		i;

	i = -1;
	envi = env_to_strtab(env);
	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		if (execve(av[0], av, envi) == -1)
		{
			ft_memdel((void **)&envi);
			error_wgcmd(av[0]);
		}
		else
			;
	}
	ft_memdel((void **)&envi);
}
