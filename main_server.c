/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:36:29 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/03 18:01:40 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

t_sigchar	*g_char;

void	init(void)
{
	g_char->c = 0;
	g_char->bit = 0;
}

void	print_pid(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
}

void	intercom(int sig)
{
	if (sig == SIGUSR1)
		g_char->c += ft_pow(g_char->bit, 2);
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
	while (1)
		;
	return (0);
}
