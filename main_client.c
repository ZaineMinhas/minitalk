/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:37:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/01 19:20:19 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_error(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Only two parameters required\n");
		exit(1);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_putstr("The pid must be greater than 0\n");
		exit(1);
	}
}

static void	send(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_putstr("Wrong pid !!!\n");
		exit(1);
	}
}

static void	share_signal(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 7)
	{
		if (c % 2)
			send(pid, SIGUSR1);
		else
			send(pid, SIGUSR2);
		c /= 2;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	check_error(argc, argv);
	i = -1;
	ft_putstr("send bytes : [");
	ft_putnbr(ft_strlen(argv[2]));
	ft_putstr("]\n");
	j = 0;
	while (argv[2][++i])
	{
		share_signal(argv[2][i], ft_atoi(argv[1]));
		j++;
		ft_putstr("\rrecive bytes : [");
		ft_putnbr(j);
		ft_putstr("]");
	}
}
