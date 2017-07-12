/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:29:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 02:24:25 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_freetab(void **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
	{
		ft_memdel(tab[i]);
	}
	ft_memdel(tab);
}
