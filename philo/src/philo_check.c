/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:01:00 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/04 19:07:10 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	philo_dead(t_philo *philo)
{
	bool	result;
	t_data	*data;

	data = philo->data;
	result = false;
	if (get_time() - get_last_eat_time(philo) > get_die_time(data)
		&& get_philo_state(philo) != FULL)
	{
		set_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}
