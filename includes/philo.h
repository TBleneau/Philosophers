/*
** EPITECH PROJECT, 2018
** philo.h
** File description:
** Created by Thomas BLENEAU
*/

#ifndef PHILO_H_
	#define PHILO_H_

	#include <stdbool.h>
	#include <pthread.h>

	typedef struct args_s
	{
		size_t n_cycle;
		size_t b_rice;
		char *core_state;
		struct philo_s *tab;
	} args_t;

	typedef struct philo_s
	{
		size_t id;
		args_t *core;
		char state;
		pthread_mutex_t mutex_left;
		pthread_mutex_t *mutex_right;
		pthread_t thread;
	} philo_t;

	enum error_e {
		E_ARGS,
		E_OPTS,
		E_NUMB
	};

	int error_display(char const *const, enum error_e);
	int error_arguments(int const, char **);
	void *philosopher_algo(void *);
	int philosopher_create(args_t *);
	int philosopher_debug(philo_t const *const);
	int philosopher_free(philo_t **);
	int options_free(args_t *);
	int options_parser(args_t *, char **);
	void update_eat(philo_t *);
	void update_sleep(philo_t *philosopher);
	void update_think(philo_t *philosopher);

#endif /* !PHILO_H_ */
