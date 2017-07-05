/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 05:30:33 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/29 03:19:18 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	ft_putprompt(char *pwd, char **env);
void	ft_env(char **env);
char	*ft_getenv_var(char *var, char **env);
char	*ft_get_var_name(char *varpath);
char	**ft_getenv(char **env);
char	**ft_setenv(char **env);
char	**ft_unsetenv(char **env);
size_t	ft_envlen(char **env);
char	*ft_storenv(char *var, char **env);
char	**ft_sentsplit(char *sentence);

#endif
