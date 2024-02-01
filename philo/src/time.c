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

#include "philo.h"

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