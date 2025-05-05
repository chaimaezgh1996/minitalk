/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:44:56 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/04 17:43:05 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	write_char(int *s)
{
	int			bnr[8];
	int			j;
	int			res;

	res = 0;
	bnr[0] = 1;
	j = 0;
	while (++j < 8)
		bnr[j] = bnr[j - 1] * 2;
	j = -1;
	while (++j < 8)
		if (s[j] == 1)
			res = res + bnr[j];
	write(1, &res, 1);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	a;
	int			arr[8];
	int			j;

	context = NULL;
	if (a != info->si_pid)
	{
		j = -1;
		while (++j < 8)
			arr[j] = 0;
		a = info->si_pid;
		i = 0;
	}
	if (sig == SIGUSR2)
		arr[i] = 1;
	else if (sig == SIGUSR1)
		arr[i] = 0;
	if (i == 7)
	{
		write_char(arr);
		i = 0;
	}
	else
		i++;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr (getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
