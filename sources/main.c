/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Created by Thomas BLENEAU
*/

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "extern.h"
#include "philo.h"

int main(int argc, char **argv)
{
	args_t *options = calloc(1, sizeof(args_t));

	if (options == NULL)
		return (84);
	RCFStartup(argc, argv);
	if (error_arguments(argc, argv) || options_parser(options, argv) == -1)
		return (84);
	if (philosopher_create(options)) {
		options_free(options);
		return (84);
	}
	options_free(options);
	RCFCleanup();
	return (0);
}
