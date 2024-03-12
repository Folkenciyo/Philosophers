/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:20:54 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/30 19:20:54 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mut_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return (last_eat_time);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_time);
	return (time);
}

uint64_t	get_die_time(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mut_die_t);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mut_die_t);
	return (die_time);
}

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep_t);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_t);
	return (sleep_time);
}

uint64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* 

struct timeval {
	time_t      tv_sec;     // seconds
	suseconds_t tv_usec;    // microseconds
};

struct timeval tiempo_actual;
// Obtener la fecha y hora actual
	if (gettimeofday(&tiempo_actual, NULL) == -1) {
		perror("Error al obtener la fecha y hora actual");
		return 1;  // Salir con código de error
	}

// Imprimir la información sobre la fecha y hora actual
	printf("tiempo en años: %ld\n", tiempo_actual.tv_sec / 31536000);
	printf("tiempo en meses: %ld\n", tiempo_actual.tv_sec / 2592000);
	printf("tiempo en dias: %ld\n", tiempo_actual.tv_sec / 86400);
	printf("tiempo en horas: %ld\n", tiempo_actual.tv_sec / 3600);
	printf("tiempo en minutos: %ld\n", tiempo_actual.tv_sec / 60);
	printf("Segundos: %ld\n", tiempo_actual.tv_sec);
	printf("Microsegundos: %ld\n", tiempo_actual.tv_usec);
 */