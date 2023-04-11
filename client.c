/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:20:59 by wmoughar          #+#    #+#             */
/*   Updated: 2023/02/27 14:20:59 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_state;

void	success_msg(int n)
{
	static int	bit;

	g_state = 1;
	if (n == SIGUSR2)
		bit++;
	if (n == SIGUSR1)
	{
		ft_printf("Message Received: %d characters\n", bit / 8);
		exit(0);
	}
	return ;
}

int	ft_convert(char c, int client, int i)
{
	int	n;

	while (i >= 0)
	{
		n = 0;
		if (c & (1 << i))
			kill (client, SIGUSR1);
		else
			kill (client, SIGUSR2);
		while (g_state == 0)
		{
			usleep(100000);
			n++;
			if (n == 5)
			{
				ft_printf("Server took too long to respond\n");
				exit(1);
			}
		}
		g_state = 0;
		i--;
	}
	return (0);
}

//atoi is used to convert the received pid from string to int
int	main(int argc, char *argv[])
{
	int	n;
	int	i;

	if (argc != 3)
	{
		ft_printf("Number of arguments should be 3\n");
		return (1);
	}
	i = 0;
	n = ft_atoi(argv[1]);
	signal(SIGUSR1, success_msg);
	signal(SIGUSR2, success_msg);
	while (argv[2][i])
		ft_convert(argv[2][i++], n, 7);
	ft_convert(0, n, 7);
	return (0);
}
