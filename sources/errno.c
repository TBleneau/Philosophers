/*
** EPITECH PROJECT, 2018
** errno.c
** File description:
** Created by Thomas BLENEAU
*/

#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

static char const *const error_type[] = {
	[E_ARGS] = "Wrong number of arguments",
	[E_OPTS] = "Invalid options",
	[E_NUMB] = "Invalid values. Use values more than 1",
};

int error_display(char const *const name, enum error_e const value)
{
	fprintf(stderr, "%s: %s\n", name, error_type[value]);
	return (-1);
}
