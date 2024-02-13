/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:40 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/17 18:20:40 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/philo.h"

int	philosophers(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (MALLOC_ERROR);
	if (init_data(data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(data);
	//init_forks(&data);
	//run_threads(&data);
	//join_threads(&data);
	//free_data(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv) != 0)
	{
		print_instruction();
		return (WRONG_INPUT);
	}
	if (philosophers(argc, argv) != 0)
		return (MALLOC_ERROR);
	return (0);
}