/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 04:53:36 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/24 05:24:04 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "../../minishell.h"

typedef struct		s_export
{
	char			*var;
	struct s_export *left;
	struct s_export *right;

}					t_export;

#endif
