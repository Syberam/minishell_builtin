/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 22:30:57 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 08:31:06 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/echo.h"

char			*ft_makeconv(char *str, int i, int j, size_t *ehks)
{
	char		*specials;
	char		*sp_ascode;

	specials = "abcfnrtv\\";
	sp_ascode = "\a\b\0\f\n\r\t\v\\";
	while (specials[++j - 1])
	{
		if (str[i] == specials[j - 1])
		{
			str[i - 1] = sp_ascode[j - 1];
			if (j - 1 == 2)
				ehks[2] = 1;
			if (j - 1 == 2)
				return (str);
			str = ft_ext_strjoin_free(ft_strsub(str, 0, i), str + i + 1, 1);
			break ;
		}
	}
	return (str);
}

char			*ft_convstr(char *av, size_t *ehks, t_env *env)
{
	size_t		i;
	size_t		j;
	char		*cpy;

	if (!av)
		return ("\0");
	if (av[0] == '$')
	{
		if (ft_getenv_var(av + 1, env))
			return (ft_strdup(ft_getenv_var(av + 1, env)));
		else
			return (ft_strdup(""));
	}
	cpy = ft_strdup(av);
	i = 0;
	while (cpy[++i - 1])
	{
		if (cpy[i - 1] != 92)
			continue;
		j = 0;
		if (ehks[3] == 1)
			cpy = ft_makeconv(cpy, i, j, ehks);
	}
	return (cpy);
}

size_t			ft_setopt(char **argv, size_t *ehks)
{
	size_t		i;
	size_t		j;

	ehks[2] = 0;
	ehks[3] = 0;
	i = 0;
	j = 0;
	while (argv[++i])
	{
		if (argv[i][0] != '-')
			return (i - 1);
		j = 0;
		if (!argv[i][1] || argv[i][1] == ' ')
			return (i - 1);
		while (argv[i][++j])
		{
			if (argv[i][j] == 'n')
				ehks[0] = 1;
			if (argv[i][j] == 'e')
				ehks[3] = 1;
			if (argv[i][j] == '-')
				return (i - 1);
		}
	}
	return (i - 1);
}

/*
** ehks for Enter Hyphen Kill Special
*/

int				echo_start(char **argv, t_env *env)
{
	char		*cpy;
	size_t		ehks[4];
	size_t		ij[2];

	ehks[0] = 0;
	ehks[1] = 0;
	ij[0] = ft_setopt(argv, ehks);
	ij[1] = ij[0] + 1;
	if (!argv[1])
		ft_putchar('\n');
	if (!argv[1])
		return (0);
	while (argv[++ij[0]])
	{
		if (ij[0] > ij[1])
			ft_putchar(' ');
		cpy = ft_convstr(argv[ij[0]], ehks, env);
		ft_putstr(cpy);
		free(cpy);
		if (ehks[2] == 1)
			return (0);
	}
	if (ehks[0] == 0)
		ft_putchar('\n');
	return (0);
}
