/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:36:29 by zminhas           #+#    #+#             */
/*   Updated: 2021/08/30 17:32:47 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
}

int	main(void)
{
	print_pid();
	while (1)
		;
	return (0);
}
