/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strminimize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 00:39:20 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 08:44:18 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmini(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = (char)ft_tolower((char)str[i]);
		i++;
	}
	return (str);
}
