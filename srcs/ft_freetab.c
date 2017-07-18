/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:29:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/17 20:32:01 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_freetab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (tab[++i])
		ft_memdel((void **)&tab[i]);
	ft_memdel((void **)&tab);
}
