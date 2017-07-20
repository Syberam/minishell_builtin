/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:34:09 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/20 23:28:30 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_segcount(char const *s, char c)
{
	int		reading;
	int		segcount;

	if (!s)
		return (0);
	reading = 0;
	segcount = 0;
	while (*s)
	{
		if (!reading && *s != c)
		{
			reading = 1;
			segcount++;
		}
		else if (*s == c)
			reading = 0;
		s++;
	}
	return (segcount);
}

size_t		ft_seglen(char const *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		nbw;
	int		reading;
	char	*str;
	char	*word;

	nbw = ft_segcount(s, c);
	if (!s || !(ret = (char **)ft_memalloc(sizeof(char *) * (nbw + 1))))
		return ((char **)NULL);
	reading = 0;
	str = (char *)s - 1;
	while (nbw && ++str)
	{
		if (reading == 0 && *str != c && nbw-- && !(reading = 0))
		{
			if (!(word = (char *)ft_memalloc(2 + ft_seglen(str, c))))
				return ((char **)NULL);
			*ret++ = word;
			while (*str && *str != c)
				*word++ = *str++;
			*word = '\0';
		}
	}
	*ret = NULL;
	return (ret -= ft_segcount(s, c));
}
