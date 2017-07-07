/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:30:33 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/07 05:35:56 by sbonnefo         ###   ########.fr       */
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

void	ft_putprompt(char *pwd, t_env *env);
void	ft_env(t_env *env);
char	*ft_getenv_var(char *var, t_env *env);
char	*ft_get_var_name(char *varpath);
t_env	*ft_getenv(char **env);
t_env	*ft_setenv(char *newvar, t_env *env, int overwrite);
char	**ft_unsetenv(const char *name, t_env *env);
size_t	ft_envlen(t_env *env);
char	*ft_storenv(char *var, t_env *env);
char	**ft_sentsplit(char *sentence);
int		cd_start(char **av, t_env *env);
int		echo_start(int ac, char **av, t_env *env);
void	error_wgcmd(char *cmd);
void	env_start(char **av, t_env *env);

#endif
