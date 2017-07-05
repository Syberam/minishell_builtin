/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:46:06 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/05 20:03:47 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H
# include "../../minishell.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# define CD_SUCCESS			1
# define CD_NOHOME			-1
# define CD_WGDIR			-2
# define CD_PERMDEN			-3
# define CD_CHDIR_FAILURE	-10

typedef	struct			s_opt
{
	char				p;
	char				l;
	char				oldp;
	char				lastop;
	size_t				start;
}						t_opt;

typedef	struct stat		t_stat;

char					cd_step1(char *destpath, char **env, t_opt *options);
char					cd_step2(char *destpath, char **env, t_opt *options);
char					cd_step3(char *destpath, char **env, t_opt *options);
char					cd_step4(char *destpath, char **env, t_opt *options);
char					cd_step5(char *destpath, char **env, t_opt *options);
char					cd_step6(char *destpath, char **env, t_opt *options);
char					cd_step7(char *destpath, char **env, t_opt *options);
char					cd_step8(char *destpath, char **env, t_opt *options);
char					cd_step9(char *destpath);
char					cd_step10(char *destpath, char **env, t_opt *options);

char					*ft_fill_destpath(char *destpath, char **env);

int						ft_cd_errors(char err_id, char *destpath);

#endif
