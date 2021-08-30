/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:39:51 by zminhas           #+#    #+#             */
/*   Updated: 2021/08/30 17:03:18 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = -(unsigned int)n;
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(48 + nb % 10);
}
