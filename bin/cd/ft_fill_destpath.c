/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_destpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 23:16:15 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/23 07:13:43 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"

char	*ft_fill_destpath(char *destpath, char **env)
{
	if (destpath)
		return (ft_strdup(destpath));  //MALLOC FO FUTUR FREES !!??
	return (ft_getenv_var("HOME", env));
}
