/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:33:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/18 02:34:36 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
