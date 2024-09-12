/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:55:30 by fmartusc          #+#    #+#             */
/*   Updated: 2024/06/20 17:55:30 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

void	signal_transl(int signal)
{
	static int	whatbit;
	static char	character;

	character |= (signal == SIGUSR1);
	whatbit++;
	if (whatbit == 8)
	{
		if (character == '\0')
			write(1, "\n", 1);
		else
			ft_printf("%c", character);
		whatbit = 0;
		character = 0;
	}
	else
		character <<= 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_transl);
	signal(SIGUSR2, signal_transl);
	while (1)
		pause();
	return (0);
}
