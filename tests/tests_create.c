/*
** EPITECH PROJECT, 2018
** philosopher tests
** File description:
** create.c unit tests
*/

#include <criterion/criterion.h>
#include "philo.h"

int philosopher_fill(args_t *, size_t const);

Test(test_create01, philosopher_create)
{
	args_t opts_1;
	args_t opts_2;

	opts_1.tab = NULL;
	opts_2.n_cycle = 5;
	opts_2.b_rice = 3;
	cr_assert_eq(philosopher_create(&opts_1), 1);
	cr_assert_eq(philosopher_create(&opts_2), 0);
}

Test(test_create01, philosopher_fill)
{
	args_t opts;

	opts.n_cycle = 2;
	opts.b_rice = 5;
	opts.tab = calloc(opts.n_cycle + 1, sizeof(philo_t));
	opts.core_state = strdup("ERT");
	cr_assert_eq(philosopher_fill(&opts, 1), 0);
	cr_assert_eq(philosopher_fill(&opts, 2), 0);
}
