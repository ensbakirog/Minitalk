/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakirog <ebakirog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:05:55 by ebakirog          #+#    #+#             */
/*   Updated: 2023/10/08 00:03:29 by ebakirog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);

void	ft_send_bit(int pid, char c)
{
	int	bit;

	bit = 8;
	while (--bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	ft_atoi(const char *str)
{
	int	value;
	int	result;

	value = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		value *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * value);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Error: Insufficient argument error (!)\n");
		ft_printf("Ussage: <PID> <MESSAGE>");
		return (1);
	}
	while (*av[2])
		ft_send_bit(ft_atoi(av[1]), *av[2]++);
	ft_send_bit(ft_atoi(av[1]), '\n');
	return (0);
}
