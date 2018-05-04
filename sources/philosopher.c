/*
** EPITECH PROJECT, 2018
** philosopher.c
** File description:
** Created by Thomas BLENEAU
*/

#include <unistd.h>
#include <pthread.h>
#include "philo.h"
#include "extern.h"

static int philosopher_eat(philo_t *philosopher, size_t *inc)
{
	pthread_mutex_lock(&philosopher->mutex_left);
	pthread_mutex_lock(philosopher->mutex_right);
	lphilo_take_chopstick(&philosopher->mutex_left);
	lphilo_take_chopstick(philosopher->mutex_right);
	lphilo_eat();
	*inc += 1;
	usleep(5000);
	lphilo_release_chopstick(&philosopher->mutex_left);
	lphilo_release_chopstick(philosopher->mutex_right);
	pthread_mutex_unlock(&philosopher->mutex_left);
	pthread_mutex_unlock(philosopher->mutex_right);
	return (0);
}

static int philosopher_sleep(philo_t *philosopher)
{
	lphilo_sleep();
	usleep(5000);
	if (philosopher->core->n_cycle > 2)
		philosopher->state = 'T';
	else
		philosopher->state = 'E';
	return (0);
}

static int philosopher_think(philo_t *philosopher)
{
	pthread_mutex_lock(&philosopher->mutex_left);
	lphilo_take_chopstick(&philosopher->mutex_left);
	lphilo_think();
	usleep(5000);
	lphilo_release_chopstick(&philosopher->mutex_left);
	pthread_mutex_unlock(&philosopher->mutex_left);
	return (0);
}

void *philosopher_algo(void *data)
{
	size_t inc = 0;
	philo_t *philo = (philo_t *) data;

	while (inc < philo->core->b_rice) {
		if (philo->state == 'E') {
			philosopher_eat(philo, &inc);
			philo->state = 'R';
		} else if (philo->state == 'R')
			philosopher_sleep(philo);
		else {
			philosopher_think(philo);
			philo->state = 'E';
		}
	}
	pthread_exit(NULL);
	return (0);
}
