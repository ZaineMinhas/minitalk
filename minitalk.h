/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:37:35 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/04 16:27:14 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include"libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sigchar
{
	char	c;
	int		bit;
}				t_sigchar;

#endif
