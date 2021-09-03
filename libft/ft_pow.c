/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:43:10 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/03 17:55:16 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int pow, int nb)
{
	int	i;

	if (!pow)
		return (1);
	i = nb;
	while (--pow)
		nb *= i;
	return (nb);
}
