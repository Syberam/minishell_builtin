/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 18:46:06 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/17 23:17:29 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H
# include "./minishell.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>

# define CD_SUCCESS			1
# define CD_NOHOME			-1
# define CD_WGDIR			-2
# define CD_PERMDEN			-3
# define CD_NOTDIR			-4
# define CD_CHDIR_FAILURE	-10

typedef	struct			s_opt
{
	char				p;
	char				l;
	char				oldp;
	char				lastop;
	size_t				start;
}						t_opt;

char					cd_step1(char *destpath, t_env *env, t_opt *options);
char					cd_step2(char *destpath, t_env *env, t_opt *options);
char					cd_step3(char *destpath, t_env *env, t_opt *options);
char					cd_step4(char *destpath, t_env *env, t_opt *options);
char					cd_step5(char *destpath, t_env *env, t_opt *options);
char					cd_step6(char *destpath, t_env *env, t_opt *options);
char					cd_step7(char *destpath, t_env *env, t_opt *options);
char					cd_step8(char *destpath, t_env *env, t_opt *options);
char					cd_step9(char *destpath);
char					cd_step10(char *destpath, t_env *env, t_opt *options);

char					*ft_fill_destpath(char *destpath, t_env *env);

void					ft_cd_errors(char err_id, char *destpath, t_opt *opti);

#endif
