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

int	run_threads(t_data *data)
{
	int	i;
	int	num_philos;

	i = 0;
	num_philos = get_nb_philos(data);
	data->start_time = get_time();
	while (++i <= num_philos)
	{
		if (pthread_create(data->philo_ths, NULL,
				&routine, &data->philos[i - 1]) != 0)
			return (PTHREAD_ERROR);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (MALLOC_ERROR);
	if (init_data(data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(data);
	init_forks(data);
	run_threads(data);
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
