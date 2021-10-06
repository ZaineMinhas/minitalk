/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:37:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/10/06 16:06:02 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

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

static void	share_len(int len, int pid)
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
		usleep(100);
	}
}

static void	share_char(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c % 2)
		{
			//printf("1");
			send(pid, SIGUSR1);
		}
		else
		{
			//printf("0");
			send(pid, SIGUSR2);
		}
		c /= 2;
		usleep(100);
	}
	//printf("\n");
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	check_error(argc, argv);
	share_len(ft_strlen(argv[2]), ft_atoi(argv[1]));
	i = -1;
	j = ft_strlen(argv[2]);
	while (argv[2][++i])
	{
		share_char(argv[2][i], ft_atoi(argv[1]));
		ft_putstr("\rbytes received : [");
		ft_putnbr(i + 1);
		ft_putstr(" / ");
		ft_putnbr(j);
		ft_putstr("]");
	}
}
