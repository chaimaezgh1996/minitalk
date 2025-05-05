/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_help_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:59:35 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/16 10:14:55 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putnbr(int s)
{
	int	a;

	if (s > 9)
	{
		ft_putnbr (s / 10);
		ft_putnbr (s % 10);
	}
	else
	{
		a = s + '0';
		write(1, &a, 1);
	}
}

int	sequance(int res)
{
	if (res < 224)
		return (2);
	else if (res < 240)
		return (3);
	else
		return (4);
}

int	to_help(int res)
{
	write(1, &res, 1);
	return (0);
}
