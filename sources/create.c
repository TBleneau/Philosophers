/*
** EPITECH PROJECT, 2018
** create.c
** File description:
** Created by Thomas BLENEAU
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include "philo.h"
#include "extern.h"

int philosopher_fill(args_t *opts, size_t const inc)
{
	opts->tab[inc].id = inc;
	opts->tab[inc].core = opts;
	opts->tab[inc].state = opts->core_state[inc % 3];
	pthread_mutex_init(&opts->tab[inc].mutex_left, NULL);
	opts->tab[inc].mutex_right =
		&opts->tab[(inc + 1) % opts->n_cycle].mutex_left;
	pthread_create(&opts->tab[inc].thread, NULL,
			philosopher_algo, &opts->tab[inc]);
	return (0);
}

int philosopher_create(args_t *opts)
{
	size_t inc = 0;

	opts->tab = calloc(opts->n_cycle + 1, sizeof(philo_t));
	opts->core_state = strdup("ERT");
	if (opts->tab == NULL || opts->core_state == NULL)
		return (1);
	while (inc < opts->n_cycle) {
		philosopher_fill(opts, inc);
		inc += 1;
	}
	inc = 0;
	while (inc < opts->n_cycle) {
		pthread_join(opts->tab[inc].thread, NULL);
		inc += 1;
	}
	return (0);
}
