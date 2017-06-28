/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testParsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 11:10:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/27 18:40:32 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	ft_state_ii(char state, char t)
{
	ft_putchar('G');
	if ((state == 'A' || state =='W') && t == '\\')	
		return ('G');
	ft_putchar('Y');
	if ((t == '`' && (state == 'W' || state == 'A' || state == 'B'
			|| state == 'E' || state == 'H')) || state == 'Y')
		return ('Y');
	ft_putchar('X');
	if ((t == 0 && (state == 'B' || state == 'D' || state == 'E'
					|| state == 'G' || state == 'H')) || state == 'X')
		return ('X');
	ft_putchar('X');
	return ('X');
}

char	ft_state(char state, char t)
{
	char	*t1;

	t1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@%^-_+=;:,.~/?{}[]";
	ft_putchar('A');
	if (state == 'A' && t == ' ')
		return ('A');
	ft_putchar('B');
	if ((state == 'A' || state == 'W')  && t == '"')
		return ('B');
	if ((state == 'B' || state == 'E' || state == 'H') && t == '\\')
		return ('C');
	ft_putchar('D');
	if (((state == 'A' || state == 'W') && t == '\'') || (state == 'D'
			&& (ft_strchr(t1, t) || t == ' ' || t == '"' || t == '\\' || t == '`'))) 
		return ('E');
	ft_putchar('A');
	if ((state == 'B' || state == 'C' || state == 'E' || state == 'H')
				&& (ft_strchr(t1, t) || t == ' ' || t == '\''))
		return ('E');
	ft_putchar('H');
	if (state == 'C' && (t == '"' || t == '\\' || t == 0 || t == '`'))
		return ('H');
	ft_putchar('F');
	if (((state == 'A' || state == 'W') && t == 0) || (state == 'W' && t == ' '))
		return ('F');
	ft_putchar('W');
	if (((state == 'W' || state == 'A') && ft_strchr(t1, t))
		|| ((state == 'B' || state == 'E' || state == 'H') && t == '"')
			|| (state == 'D' && t =='\'') || (state == 'G' && t != 0))
		return ('W');
	return (ft_state_ii(state, t));
}

int		ft_arg(char *str_part)
{
	char	state;
	size_t	i;

	state = 'A';
	i = 0;
	while (state != 'F')
	{
		ft_putchar('\t');
		ft_putchar(state);
		ft_putchar('\t');
		ft_putchar(str_part[i]);
		ft_putchar('\n');
		if ((state = ft_state(state, str_part[i])) == 'X')
			return (-1);
		else if (state == 'Y')
			return (-2);
		i++;
	}
	return (i);
}

int		ft_cntwords(char *sentence)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	j = 0;
	w = 0;
	while (sentence[i])
	{
		if ((j = ft_arg(sentence + i)) < 0)
			return (j);
		i += j;
		w++;
	}
	return (w);
}

char	**ft_sentsplit(char *sentence)
{
	char	**split;
	char	nbw;
	int		start;
	int		end;
	int		i;

	nbw = ft_cntwords(sentence);
	split = (char **)ft_memalloc(sizeof(char *) * (nbw + 1));
	i = 0;
	start = 0;
	while (sentence[start])
	{
		if ((end = ft_arg(sentence + start)) < 0)
		{
			ft_putendl_fd("MiniShell: Wrong quoting", 2);
			return (NULL);
		}
		split[i] = ft_strsub(sentence, start, end - start);
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putendl(split[i]);
		ft_putchar('\n');
		ft_putchar('\n');
		start = (sentence[end]) ? end : end;
		++i;
	}
	return (split);
}

