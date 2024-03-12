/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:23:32 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/04 19:08:28 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int take_left_fork(t_philo *philo)
{
	if (philo_died(philo) || get_philo_state(philo) == FULL)
		return (1);
	
	return (0);
}
int	take_forks(t_philo *philos)
{
	if (get_nb_philos(philos->data) == 1)
		return (handle_a_philo(philos));
/* 	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	} */
	return (0);
}
