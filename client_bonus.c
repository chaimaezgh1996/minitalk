/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:44:52 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/16 09:58:48 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	check_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+') 
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}

void	send_msg(int a, unsigned char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = c % 2;
		c = c / 2;
		if (bit == 1)
			kill (a, SIGUSR2);
		else
			kill (a, SIGUSR1);
		usleep(500);
		i++;
	}
}

void	handle_signal_cl(int sig, siginfo_t *info, void *context)
{
	info = NULL;
	context = NULL;
	if (sig == SIGUSR1)
		write (1, "message recived\n", 16);
}

int	main(int argc, char **argv)
{
	int					a;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc == 3)
	{
		sa.sa_sigaction = handle_signal_cl;
		sigaction(SIGUSR1, &sa, NULL);
		if (check_pid(argv[1]) == 0)
			return (1);
		a = ft_atoi(argv[1]);
		if (a <= 2)
			return (1);
		while (argv[2][i] != '\0')
		{
			send_msg (a, argv[2][i]);
			i++;
		}
		send_msg (a, argv[2][i]);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
