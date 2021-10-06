/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:37:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/06 19:06:05 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_error(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr("Only two parameters required\n");
	if (ft_atoi(argv[1]) <= 0)
		ft_putstr("The pid must be greater than 0\n");
	exit(1);
}

static void	send(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_putstr("Wrong pid !!!\n");
		exit(1);
	}
}

static void	share_len(int len, int pid, int speed)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len % 2)
			send(pid, SIGUSR1);
		else
			send(pid, SIGUSR2);
		len /= 2;
		usleep(speed);
	}
}

static void	share_char(char c, int pid, int speed)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c % 2)
			send(pid, SIGUSR1);
		else
			send(pid, SIGUSR2);
		c /= 2;
		usleep(speed);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	check_error(argc, argv);
	share_len(ft_strlen(argv[2]), ft_atoi(argv[1]), 50);
	i = -1;
	ft_putnbr(ft_strlen(argv[2]));
	while (argv[2][++i])
		share_char(argv[2][i], ft_atoi(argv[1]), 50);
	return (0);
}
