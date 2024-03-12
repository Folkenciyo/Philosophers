/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:12:48 by juguerre          #+#    #+#             */
/*   Updated: 2024/03/12 11:02:47 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(int color, t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iter(data))
		printf("%lu \033[0;%dm%d %s\e[0m\n", time, color, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	print_mut(t_data *data, char *msg)
{
	pthread_mutex_lock(&data->mut_print);
	printf("%s\n", msg);
	pthread_mutex_unlock(&data->mut_print);
}
