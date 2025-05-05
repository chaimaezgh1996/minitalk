/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 02:05:43 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/16 12:23:46 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

int		check_pid(char *s);
int		ft_atoi(char *str);
void	send_msg(int a, unsigned char c);
void	ft_putnbr(int s);
void	handle_signal(int sig, siginfo_t *info, void *context);
void	write_char(int *s);

#endif