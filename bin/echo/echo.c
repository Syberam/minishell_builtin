/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 22:30:57 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/23 00:41:21 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

char			*ft_makeconv(char *str, int i, int j, int *ehk)
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
				ehk[2] = 1;
			if (j - 1 == 2)
				return (str);
			str = ft_ext_strjoin_free(ft_strsub(str, 0, i), str + i + 1, 1);
			break ;
		}
	}
	return (str);
}

char			*ft_convstr(char *av, int *ehk, char **env)
{
	size_t		i;
	size_t		j;
	char		*cpy;

	if (!av)
		return ("\0");
	if (av[0] == '$')
		return (ft_strdup(ft_getenv_var(av + 1, env)));
	cpy = ft_strdup(av);
	i = 0;
	while (cpy[++i - 1])
	{
		if (cpy[i - 1] != 92)
			continue;
		j = 0;
		cpy = ft_makeconv(cpy, i, j, ehk);
	}
	return (cpy);
}

/*
** ehk for Enter Hyphen Kill
*/

int				main(int argc, char **argv, char **env)
{
	char		*cpy;
	int			ehk[3];
	int			i;

	i = 0;
	while (++i < argc)
	{
		if (i == 1 && !ft_strcmp(argv[i], "-n\0"))
			ehk[0] = 3 - (++i);
		if (i == 1 && !ft_strcmp(argv[i], "-\0"))
			ehk[1] = 3 - (++i);
		if (i > 1 + ehk[0] + ehk[1])
			ft_putchar(' ');
		cpy = ft_convstr(argv[i], ehk, env);
		ft_putstr(cpy);
		//free(cpy);
		ehk[0] = 0;
		ehk[1] = 0;
		if (ehk[2] == 1)
			return (0);
	}
	if (ehk[0] == 0)
		ft_putchar('\n');
	return (0);
}
