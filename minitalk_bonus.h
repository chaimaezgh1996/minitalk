/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:05:43 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/16 12:23:44 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int s);
int		sequance(int res);
int		to_help(int res);
void	compleat_function(int a, int *seq, int res, int *c);
void	write_char(int *s, int a);
void	handle_signal(int sig, siginfo_t *info, void *context);
int		check_pid(char *s);
int		ft_atoi(char *str);
void	send_msg(int a, unsigned char c);
void	handle_signal_cl(int sig, siginfo_t *info, void *context);

#endif