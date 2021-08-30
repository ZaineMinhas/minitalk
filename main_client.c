/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:37:23 by zminhas           #+#    #+#             */
/*   Updated: 2021/08/30 18:47:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_error(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr("");
	if (ft_atoi(argv[1]) <= 0)
		ft_putstr("");
}

void	send(int signal, int pid)
{
	if (kill(pid, signal) == -1)
		ft_putstr("");
}

void	share_signal(char c, int pid)
{
	
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	check_error(argc, argv);
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		share_signal(argc[2][i], pid);
}
