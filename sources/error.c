/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** Created by Thomas BLENEAU
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "philo.h"

static  char const *const options[3] = {
	"-p",
	"-e",
	NULL
};

int is_num(char const *const value)
{
	int ret = 0;
	size_t inc = 0;

	for (inc = 0; value && value[inc]; inc++) {
		if (isalpha(value[inc])) {
			ret = 1;
			break;
		}
	}
	return (ret);
}

int compare_options(char const *const name)
{
	int cmp = 0;
	size_t inc = 0;

	while (options[inc] && inc < 3) {
		cmp = strcmp(name, options[inc]);
		if (cmp == 0)
			return (0);
		inc += 1;
	}
	if (cmp != 0)
		return (1);
	return (0);
}

int error_options(char **argv)
{
	size_t inc = 1;
	size_t ret = 0;

	while (argv && argv[inc]) {
		if (argv[inc][0] == '-')
			ret = compare_options(argv[inc]);
		if (ret == 1)
			break;
		inc += 1;
	}
	if (ret == 0) {
		if ((strcmp(argv[1], options[0]) == 0 &&
			strcmp(argv[3], options[1]) == 0) ||
			(strcmp(argv[1], options[1]) == 0 &&
			strcmp(argv[3], options[0]) == 0))
			ret = 0;
		else
			ret = 1;
	}
	return (ret);
}

int error_numbers(char **argv)
{
	size_t inc = 1;
	size_t ret = 0;

	while (argv && argv[inc]) {
		if (compare_options(argv[inc]))
			ret = is_num(argv[inc]);
		if (ret == 1)
			break;
		inc += 1;
	}
	return (ret);
}

int error_arguments(int const argc, char **argv)
{
	if (argc != 5)
		return (error_display(argv[0], E_ARGS));
	if (error_options(argv))
		return (error_display(argv[0], E_OPTS));
	if (error_numbers(argv))
		return (error_display(argv[0], E_NUMB));
	return (0);
}
