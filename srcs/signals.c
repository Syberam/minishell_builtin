/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:28:06 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/07/11 10:17:40 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_handler_father(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\b\b  \b\b\n$>", 9);
		return ;
	}
}

void		ft_handler_child(int sig)
{
	if (wait(0) == -1)
		return ;
	if (sig == SIGINT)
		write(1, "\b\b  \b\b\n$>", 9);
}
