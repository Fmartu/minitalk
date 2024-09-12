/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:21:45 by fmartusc          #+#    #+#             */
/*   Updated: 2024/06/20 17:21:45 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <signal.h>

void	signal_transf(int pid, unsigned char sentchar);
int		ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	pid_t	serv_pid;
	int		i;

	if (argc != 3)
		exit(0);
	i = 0;
	serv_pid = ft_atoi(argv[1]);
	while (argv[2][i])
		signal_transf(serv_pid, argv[2][i++]);
	signal_transf(serv_pid, 0);
	return (0);
}

void	signal_transf(int pid, unsigned char input)
{
	int				i;
	unsigned char	tmpchar;

	if (pid < 0)
		exit(0);
	i = 8;
	tmpchar = input;
	while (i > 0)
	{
		i--;
		tmpchar = input >> i;
		if (tmpchar % 2 != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (420);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
