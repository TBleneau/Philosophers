/*
** EPITECH PROJECT, 2018
** options.c
** File description:
** Created by Thomas BLENEAU
*/

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "extern.h"
#include "philo.h"

int options_free(args_t *options)
{
	free(options->core_state);
	free(options->tab);
	free(options);
	return (0);
}

int options_parser(args_t *options, char **argv)
{
	if (strcmp(argv[1], "-p") == 0) {
		options->n_cycle = atol(argv[2]);
		options->b_rice = atol(argv[4]);
	} else {
		options->n_cycle = atol(argv[4]);
		options->b_rice = atol(argv[2]);
	}
	return ((options->n_cycle > 1 && options->b_rice > 0) ? 0 :
		error_display(argv[0], E_NUMB));
}
