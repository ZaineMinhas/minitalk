/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:36:29 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/05 19:44:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_sigchar	g_char;

static void	init(void)
{
	g_char.c = 0;
	g_char.bit = 0;
}

static void	len_calc(int sig)
{
	if (sig == SIGUSR1)
			g_char.len += ft_pow(2, g_char.bit);
	if (g_char.bit == 32)
	{
		g_char.str = malloc(sizeof(char) * (g_char.len + 1));
		if (!g_char.str)
			exit(1);
		g_char.bit = -1;
	}
}

static void	intercom(int sig)
{
	if (!g_char.str)
		len_calc(sig);
	else
	{
		if (sig == SIGUSR1)
		{
			printf("+ char.c = %d + 2^%d == %d\n", g_char.c, g_char.bit, ft_pow(2, g_char.bit));
			g_char.c += ft_pow(2, g_char.bit);
		}
		else
			printf("- char.c = %d && bit = %d\n", g_char.c, g_char.bit);
		if (g_char.bit == 7)
		{
			printf("int char = %d\nchar = %c\n", g_char.c, g_char.c);
			printf("\n");
			g_char.str[g_char.i++] = g_char.c;
			init();
		}
	}
	if (g_char.i == g_char.len)
	{
		g_char.str[g_char.i] = 0;
		ft_putstr(g_char.str);
		//free(g_char.str);
	}
	g_char.bit++;
}

int	main(void)
{
	init();
	g_char.i = 0;
	g_char.len = 0;
	g_char.str = NULL;
	ft_putnbr(getpid());
	ft_putchar('\n');
	if (signal(SIGUSR1, intercom) == SIG_ERR
		|| signal(SIGUSR2, intercom) == SIG_ERR)
		return (1);
	while (19)
		pause();
	return (0);
}
