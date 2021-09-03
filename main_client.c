/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:37:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/03 17:33:59 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_error(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr("\n");
	if (ft_atoi(argv[1]) <= 0)
		ft_putstr("\n");
}

void	share_signal(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c % 2)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr("\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr("\n");
		}
		c /= 2;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	check_error(argc, argv);
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		share_signal(argv[2][i], pid);
}
