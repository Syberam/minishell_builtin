/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:28:06 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/19 04:08:12 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_handler_father(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\b\b  \b\b\n");
		ft_putprompt(NULL);
		return ;
	}
}

void		ft_handler_child(int sig)
{
	if (wait(0) == -1)
		return ;
	if (sig == SIGINT)
		ft_putstr("\b\b");
}
