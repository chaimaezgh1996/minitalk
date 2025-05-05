/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:44:56 by czghoumi          #+#    #+#             */
/*   Updated: 2025/05/05 23:07:53 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static char	*special_char(int a)
{
	static char	*special_char;

	special_char = (char *)malloc((a + 1));
	if (special_char == NULL)
		return (NULL);
	special_char [a] = '\0';
	return (special_char);
}

void	compleat_function(int a, int *seq, int res, int *c)
{
	static char	*special;

	if (special == NULL)
		special = special_char(*c);
	special [*c - *seq] = res;
	(*seq)--;
	if (*seq == 0)
	{
		write (1, special, *c);
		free (special);
		special = NULL;
	}
	if (res == '\0')
		kill (a, SIGUSR1);
}

void	write_char(int *s, int a)
{
	static int	seq;
	static int	c;
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
	if (res <= 127)
		seq = to_help(res);
	else if (res >= 192)
	{
		seq = sequance(res);
		c = seq;
	}
	compleat_function(a, &seq, res, &c);
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
		write_char(arr, a);
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
