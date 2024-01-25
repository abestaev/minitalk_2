/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:48:58 by albestae          #+#    #+#             */
/*   Updated: 2024/01/25 14:01:36 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	btoa(char c)
{
	static char	*str = NULL;

	if (c)
		str = ft_strjoin(str, c);
	else
	{
		ft_putstr(str);
		ft_putstr("\n");
		free(str);
		str = NULL;
	}
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0;

	if (signum == SIGUSR2)
		c = (c << 1) | 1;
	else if (signum == SIGUSR1)
		c = c << 1;
	if (bit < 7)
		bit++;
	else
	{
		btoa(c);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
