/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaniber <akaniber@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:53:37 by akaniber          #+#    #+#             */
/*   Updated: 2023/01/31 15:43:06 by akaniber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_input(int signal)
{
	static unsigned int	letter;
	static int			counter;

	counter = (counter + 1) % 8;
	letter = (letter << 1) | (signal == TRUE);
	if (!counter)
		ft_printf("%c", letter);
}

int	main(void)
{
	ft_printf("Server started with PID:%d\n", getpid());
	signal(TRUE, write_input);
	signal(FALSE, write_input);
	while (1)
		pause();
	return (0);
}
