/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:11:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/12 06:54:17 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*sdup;
	int		i;

	if (!s1 || !s1[0])
		return (NULL);
	i = 0;
	if (!(sdup = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] != 0)
	{
		sdup[i] = s1[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}
