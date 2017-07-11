/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:29:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 08:48:13 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_freetab(void **tab)
{
	int	i;

	i = 0;
	while (tab[++i])
	{
		ft_memset(tab[i], 0, ft_strlen((char *)tab[i]));
		ft_memdel(&*tab[i]);
	}
	ft_memdel(tab[i]);
	ft_memset(&*tab, 0, sizeof(tab));
	ft_memdel(tab);
}
