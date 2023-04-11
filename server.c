/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:13:53 by wmoughar          #+#    #+#             */
/*   Updated: 2023/02/23 11:13:53 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int n, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	client;
	static char	bit;

	(void)ucontext;
	client = info->si_pid;
	if (n == SIGUSR1)
		c = (c << 1) | 1;
	else if (n == SIGUSR2)
		c <<= 1;
	if (++bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill(client, SIGUSR1);
			client = 0;
			write(1, "\n", 1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill(client, SIGUSR2);
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
