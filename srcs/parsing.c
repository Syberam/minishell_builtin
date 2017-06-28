/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 05:40:42 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/25 22:22:51 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			**ft_quoterror(char quote)
{
	ft_putstr_fd("MiniShell: ", 2);
	ft_putchar_fd(quote, 2);
	ft_putendl_fd(" missing");
	return (NULL);

}

static size_t	ft_lw(char *s, char quote)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != quote)
		i++;
	if (s[i] != ' ')
	{
		while (s[i] && s[i + 1] != ' ')
			i++;
	}
	return (i);
}

static char		ft_ext_strsub(char *arg, size_t i, char quote)
{
	if (quote = 1)
		split \
	
}

static size_t	ft_nw(char const *s, char *quotes)
{
	size_t		i;
	size_t		w;
	char		quote;

	i = 0;
	w = 0;
	quote = 0;
	while (s[i])
	{
		while (s[i] && s[i] == ' '  && !quote)
			i++;
		if (s[i] == '"' || s[i] == '\'' || s[i] == '`')
			quote = (char)(ft_strlen(quotes)
					- ft_strlen(ft_strchr(quotes, s[i++])));
		if (s[i] != 0)
			w++;
		while (s[i] && s[i] != quotes[quote])
			i++;
		if (quote)
			i++;
		quote = 0;
	}
	return (i);
}

char		**ft_parsing(char *arg)
{
	char	quote;
	char	*quotes;
	char	**ac;
	size_t	i;
	size_t	nbw;

	i = 0;
	quote = 0;
	quotes = " \"'`";
	ndw = ft_nw(arg, " \"'`");
	while (arg[++i - 1])
	{
		while (s[i] && s[i] == ' '  && !quote)
			i++;
		if (arg[i] == '"' || arg[i] == '\'' || arg[i] == '`')
			quote = (char)(ft_strlen(quotes)
					- ft_strlen(ft_strchr(quotes, s[i++])));
		ac[it] = ft_ext_strsub(arg, i, quote);
		while (s[i] && s[i] != quotes[quote])
			i++;
		if (quote)
			i++;
		quote = 0;
	}
	if (quote)
		ft_quoterror(quotes[quote]);
}
