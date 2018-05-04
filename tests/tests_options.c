/*
** EPITECH PROJECT, 2018
** test_options.c
** File description:
** Created by Thomas BLENEAU
*/

#include <criterion/criterion.h>
#include "philo.h"

int options_parser(args_t *, char **);
int options_free(args_t *);

Test(test01, options_parser)
{
	args_t opts;
	char *argv_1[] = {"./philo", "-e", "34", "-p", "12", NULL};
	char *argv_2[] = {"./philo", "-e", "12", "-p", "1", NULL};
	char *argv_3[] = {"./philo", "-p", "13", "-e", "0", NULL};

	cr_assert_eq(options_parser(&opts, argv_1), 0);
	cr_assert_eq(options_parser(&opts, argv_2), -1);
	cr_assert_eq(options_parser(&opts, argv_3), -1);
}

Test(test01, options_free)
{
	args_t *opts = calloc(1, sizeof(args_t));

	opts->n_cycle = 2;
	opts->b_rice = 5;
	opts->tab = calloc(opts->n_cycle + 1, sizeof(philo_t));
	opts->core_state = strdup("ERT");
	cr_assert_eq(options_free(opts), 0);
}
