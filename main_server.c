/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:36:29 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/08 15:11:28 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sigchar	g_char;

static void	return_error(int index)
{
	if (!index)
		ft_putstr("Error\n");
	else if (index == 1)
		ft_putstr("Malloc error\n");
	else if (index == 2)
		ft_putstr("Write error\n");
	exit(1);
}

static void	init(void)
{
	g_char.c = 0;
	g_char.bit = -1;
	g_char.i = 0;
	g_char.len = 0;
	g_char.str = NULL;
}

static void	len_calc(int sig)
{
	if (sig == SIGUSR1)
		g_char.len += ft_pow(2, g_char.bit);
	if (g_char.bit == 31)
	{
		g_char.str = malloc(sizeof(char) * (g_char.len + 1));
		if (!g_char.str)
			return_error(1);
		g_char.bit = -1;
	}
}

static void	intercom(int sig)
{
	g_char.bit++;
	if (!g_char.str)
		len_calc(sig);
	else
	{
		if (sig == SIGUSR1)
			g_char.c += ft_pow(2, g_char.bit);
		if (g_char.bit == 7)
		{
			g_char.str[g_char.i++] = g_char.c;
			g_char.c = 0;
			g_char.bit = -1;
		}
	}
	if (g_char.i == g_char.len && g_char.len)
	{
		g_char.str[g_char.i + 1] = 0;
		if (write(1, g_char.str, g_char.len) == -1)
			return_error(2);
		free(g_char.str);
		init();
	}
}

int	main(void)
{
	init();
	ft_putnbr(getpid());
	ft_putchar('\n');
	if (signal(SIGUSR1, intercom) == SIG_ERR
		|| signal(SIGUSR2, intercom) == SIG_ERR)
		return (1);
	while (19)
		pause();
	return (0);
}
