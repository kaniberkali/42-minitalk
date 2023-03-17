/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:34 by akaniber          #+#    #+#             */
/*   Updated: 2023/01/31 16:03:47 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_input(int pid, char *str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		k = 7;
		while (k >= 0)
		{
			if (((str[i] >> k) & 1) == 1)
				kill(pid, TRUE);
			else
				kill(pid, FALSE);
			k--;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		send_input(ft_atoi(argv[1]), argv[2]);
	return (0);
}
