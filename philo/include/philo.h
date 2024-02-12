/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:07:39 by juguerre          #+#    #+#             */
/*   Updated: 2024/01/17 18:07:39 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <inttypes.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

# define RED "\033[0;31m"
# define DEFAULT "\033[;0m"

struct	s_data;

/**
 * @brief La estructura 't_philo' representa a un filósofo en
 * el problema de los filósofos comensales.
 * 
 * @param id El identificador único del filósofo.
 * @param nb_meals_had El número de comidas que ha tenido el filósofo.
 * @param data Un puntero a la estructura de datos compartida.
 * @param state El estado actual del filósofo (por ejemplo, pensando, comiendo, durmiendo).
 * @param left_f Un puntero al mutex del tenedor izquierdo del filósofo.
 * @param right_f Un puntero al mutex del tenedor derecho del filósofo.
 * @param mut_state Un mutex para cambiar el estado del filósofo de forma segura.
 * @param mut_nb_meals_had Un mutex para cambiar el número de comidas que ha tenido el filósofo de forma segura.
 * @param mut_last_eat_time Un mutex para cambiar la última vez que el filósofo comió de forma segura.
 * @param last_eat_time La última vez que el filósofo comió.
 */
typedef struct s_philo
{
	int				id;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}t_philo;

/**
 * @brief La estructura 't_data' representa los datos compartidos entre todos los filósofos. 
 * 
 * @param nb_philos El número total de filósofos.
 * @param nb_meals El número total de comidas que deben tener los filósofos.
 * @param nb_full_p El número de filósofos que están llenos (han comido el número requerido de comidas).
 * @param keep_iterating Un booleano para determinar si los filósofos deben seguir iterando.
 * @param eat_time El tiempo que un filósofo pasa comiendo.
 * @param die_time El tiempo que un filósofo puede pasar sin comer antes de morir.
 * @param sleep_time El tiempo que un filósofo pasa durmiendo.
 * @param start_time El tiempo en el que comenzó la simulación.
 * @param mut_eat_t Un mutex para cambiar el tiempo de comer de forma segura.
 * @param mut_die_t Un mutex para cambiar el tiempo de morir de forma segura.
 * @param mut_sleep_t Un mutex para cambiar el tiempo de dormir de forma segura.
 * @param mut_print Un mutex para imprimir de forma segura.
 * @param mut_nb_philos Un mutex para cambiar el número de filósofos de forma segura.
 * @param mut_keep_iter Un mutex para cambiar el booleano 'keep_iterating' de forma segura.
 * @param mut_start_time Un mutex para cambiar el tiempo de inicio de forma segura.
 * @param monit_all_alive Un hilo para monitorear si todos los filósofos están vivos.
 * @param monit_all_full Un hilo para monitorear si todos los filósofos están llenos.
 * @param philo_ths Un array de hilos, cada uno representando a un filósofo.
 * @param forks Un array de mutex, cada uno representando a un tenedor.
 * @param philos Un array de 't_philo', cada uno representando a un filósofo.
 */
typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}t_data;

// parse.c
int		check_input(int argc, char **argv);
int		ft_atoi(char *str);
void	print_instruction(void);
int		wrong_input_check(int argc, char **argv);
int		is_input_digit(int argc, char **argv);

// error.c
int		print_error(char *msg, int ERROR_);

#endif