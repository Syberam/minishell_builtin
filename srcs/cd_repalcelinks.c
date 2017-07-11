/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_repalcelinks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 00:52:48 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 02:30:32 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cd.h>

char		*ft_repalcelinks(char *destpath)
{
	t_stat	dirstat;
	char	**paths;
	int		i;

	paths = ft_strsplit(destpath + 1, '/');
	i = -1;
	while (paths[++i])
		paths[i] = ft_ext_strjoin_free("/", paths[i], 2);
	i = 0;
	while (paths[++i])
		paths[i] = ft_ext_strjoin_free(paths[i - 1], paths[i], 2);
	i++;
	while (--i > -1)
	{
		lstat(paths[i], &dirstat);
	}
}
