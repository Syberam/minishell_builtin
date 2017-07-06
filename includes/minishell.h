/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:30:33 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/06 23:37:08 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_env_opt
{
	char			i;
	char			v;
	char			wrg;
}					t_env_opt;

typedef	struct		s_env
{
	char			*var;
	struct s_env	*next;
	struct s_env	*prev ;
}					t_env;

void	ft_putprompt(char *pwd, char **env);
void	ft_env(char **env);
char	*ft_getenv_var(char *var, char **env);
char	*ft_get_var_name(char *varpath);
char	**ft_getenv(char **env);
char	**ft_setenv(char *new, char **env, int overwrite);
char	**ft_unsetenv(const char *name, char **env);
size_t	ft_envlen(char **env);
char	*ft_storenv(char *var, char **env);
char	**ft_sentsplit(char *sentence);
int		cd_start(char **av, char **env);
int		echo_start(int ac, char **av, char **env);
void	error_wgcmd(char *cmd);
void	env_start(char **av, char **env);

#endif
