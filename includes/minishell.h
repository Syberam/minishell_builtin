/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:30:33 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/13 04:55:51 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

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
	struct s_env	*prev;
}					t_env;

void				ft_putprompt(t_env *env);
void				ft_env(t_env *env);
void				cd_start(char **av, t_env *env);
void				env_start(char **av, t_env *env);
void				error_wgcmd(char *cmd);
void				ft_vars_to_unset(char **names, t_env *env);
void				ft_freetab(char **tab);
void				ft_handler_father(int sig);
void				ft_handler_child(int sig);

size_t				ft_envlen(t_env *env);
size_t				value_poz(char	*varline);
int					echo_start(char **av, t_env *env);

char				*ft_getenv_var(char *var, t_env *env);
char				*ft_get_var_name(char *varpath);
char				*ft_storenv(char *var, t_env *env);

char				**ft_sentsplit(char *sentence);
char				**ft_jointabs(char **tab1, char **tab2);

t_env				*ft_getenv(char **env);
t_env				*ft_setenv(char *newvar, t_env *env);
t_env				*ft_unsetenv(const char *names, t_env *env);

#endif
