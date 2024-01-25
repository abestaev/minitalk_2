/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:47:11 by albestae          #+#    #+#             */
/*   Updated: 2024/01/25 17:01:10 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int			g_catch;

static void	atob(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_catch = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		while (g_catch == 0)
			pause();
	}
}

static void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		atob(pid, str[i]);
		i++;
	}
}

static void	catch_sig_server(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR2)
		g_catch = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	g_catch = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = catch_sig_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0 || kill(ft_atoi(argv[1]), 0))
		{
			ft_putstr("Error\nInvalid PID\n");
			exit(1);
		}
		ft_putstr("sending...\n");
		send_str(ft_atoi(argv[1]), argv[2]);
		ft_putstr("send");
	}
	else
		ft_putstr("Argument Error\nSyntax > ./client SERVER_PID \"msg_to_send\"\n");
	return (0);
}
