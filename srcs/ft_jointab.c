/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:32:13 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/17 21:19:00 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char		**ft_jointabs(char **tab1, char **tab2)
{
	char	**newtab;
	int		i;
	int		j;

	if (!tab1)
		return (tab2);
	if (!tab2)
		return (tab1);
	newtab = (char **)ft_memalloc(sizeof(char *) *
					(tablen(tab1) + tablen(tab2) + 1));
	i = -1;
	while (tab1[++i])
		newtab[i] = tab1[i];
	j = -1;
	while (tab2[++j])
		newtab[i + j] = tab2[j];
	newtab[i + j] = 0;
	ft_memdel((void **)&tab1);
	ft_memdel((void **)&tab2);
	return (newtab);
}
