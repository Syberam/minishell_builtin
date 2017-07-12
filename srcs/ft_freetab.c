/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:29:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 00:45:50 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_freetab(void **tab)
{
	int	i;

	if (!tab)
		return ;
	i = -1;;
	while (tab[++i])
		free((void *)tab[i]);
	ft_memdel(tab);
}
