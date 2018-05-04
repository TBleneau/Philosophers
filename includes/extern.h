/*
** EPITECH PROJECT, 2018
** extern.h
** File description:
** Created by Thomas BLENEAU
*/

#ifndef EXTERN_H_
	#define EXTERN_H_

	#include <pthread.h>

	int RCFStartup(int ac, char **av);
	void RCFCleanup(void);
	int lphilo_eat(void);
	int lphilo_sleep(void);
	int lphilo_think(void);
	int lphilo_take_chopstick(pthread_mutex_t const *);
	int lphilo_release_chopstick(pthread_mutex_t const *);

#endif /* !EXTERN_H_ */
