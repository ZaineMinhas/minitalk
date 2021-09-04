/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:53:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/09/04 15:31:45 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_pow(int nb, int pow);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

#endif
