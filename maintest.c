
#include "libft/libft.h"

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
		while (s[i] && s[i] == ' ' && !quote)
			i++;
		if ((i == 0 && (s[i] == '"' || s[i] == '\'' || s[i] == '`')) ||
				(s[i - 1] != '\\' && (s[i] == '"' || s[i] == '\'' || s[i] == '`')))
			quote = (char)(ft_strlen(quotes)
							- ft_strlen(ft_strchr(quotes, s[i++])));
		if (s[i] != 0)
			w++;
		while (s[i])
		{
			if (quote == 1 && s[i] == quotes[quote] && i > 0 && s[i - 1] != '\\')
			{
				i++;
				break;
			}
			else if (s[i] == quotes[quote])
			{
				i++;
				break;
			}
			i++;
		}
		if (quote)
			i++;
		quote = 0;
	}
	return (w);
}
int			main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (!argc)
		return(0);
	while (argv[i])
	{
		ft_putnbr(i);
		ft_putstr(" : ");
		ft_putendl(argv[i]);
		i++;
	}
	ft_putnbr((int)ft_nw("\"salut les \" \\\"lol", " \"'`"));
	return (0);
}
