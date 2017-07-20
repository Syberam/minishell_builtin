/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/20 23:00:23 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int				main(int argc, char **argv, char **env)
{
	char		*line;
	t_env		*envi;

	envi = ft_getenv(env);
	line = NULL;
	while (argc)
	{
		signal(SIGINT, ft_handler_father);
		ft_putprompt(envi);
		if (gnl(0, &line) == 1)
		{
			argv = ft_strsplit(line, ' ');
			if (argv && argv[0])
				ft_dobin(argv, envi);
			ft_freetab(argv);
			ft_memdel((void **)&line);
		}
		else
		{
			ft_putstr("\b\b\n");
			exit(0);
		}
	}
	return (0);
}
