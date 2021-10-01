/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:36:29 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/01 16:42:03 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sigchar	*g_char;

static void	init(void)
{
	g_char->c = 0;
	g_char->bit = 0;
}

static void	print_pid(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
}

static void	intercom(int sig)
{
	if (sig == SIGUSR1)
		g_char->c += ft_pow(2, g_char->bit);
	g_char->bit++;
	if (g_char->bit == 7)
	{
		ft_putchar(g_char->c);
		init();
	}
}

int	main(void)
{
	g_char = malloc(sizeof(t_sigchar));
	init();
	print_pid();
	if (signal(SIGUSR1, intercom) == SIG_ERR
		|| signal(SIGUSR2, intercom) == SIG_ERR)
		return (1);
	while (19)
		pause();
	return (0);
}
