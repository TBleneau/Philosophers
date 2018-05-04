/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** error.c unit test
*/

#include <criterion/criterion.h>
#include "philo.h"

int is_num(char *);
int compare_options(char const *const);
int error_options(char **);
int error_numbers(char **);
int error_arguments(int, char **);

Test(test01, is_num)
{
	cr_assert_eq(is_num("toto"), 1);
	cr_assert_eq(is_num("12"), 0);
	cr_assert_eq(is_num("345a"), 1);
	cr_assert_eq(is_num("500"), 0);
	cr_assert_eq(is_num("500e02"), 1);
}

Test(test01, compare_options)
{
	cr_assert_eq(compare_options("-p"), 0);
	cr_assert_eq(compare_options("-text"), 1);
	cr_assert_eq(compare_options("--p"), 1);
	cr_assert_eq(compare_options("-verbose"), 1);
	cr_assert_eq(compare_options("-e"), 0);
	cr_assert_eq(compare_options("-erase"), 1);
}

Test(test01, error_options)
{
	char *argv_1[] = {"./philo", "-e", "34", "-p", "12", NULL};
	char *argv_2[] = {"./philo", "34", "-e", "12", "-p", NULL};
	char *argv_3[] = {"./philo", "-p", "34", "-e", "12", NULL};
	char *argv_4[] = {"./philo", "--erase", "34", "-p", "--text", NULL};

	cr_assert_eq(error_options(argv_1), 0);
	cr_assert_eq(error_options(argv_2), 1);
	cr_assert_eq(error_options(argv_3), 0);
	cr_assert_eq(error_options(argv_4), 1);
}

Test(test01, error_numbers)
{
	char *argv_1[] = {"./philo", "-e", "34", "-p", "12", NULL};
	char *argv_2[] = {"./philo", "34", "-e", "12", "-p", NULL};
	char *argv_3[] = {"./philo", "-p", "34", "-e", "12", NULL};
	char *argv_4[] = {"./philo", "--erase", "34", "-p", "--text", NULL};

	cr_assert_eq(error_numbers(argv_1), 0);
	cr_assert_eq(error_numbers(argv_2), 0);
	cr_assert_eq(error_numbers(argv_3), 0);
	cr_assert_eq(error_numbers(argv_4), 1);
}

Test(test01, error_arguments)
{
	char *argv_1[] = {"./philo", "-e", "34", "-p", "12", NULL};
	char *argv_2[] = {"./philo", "34", "-e", "12", "-p", NULL};
	int argc[3] = {1, 5, 4};

	cr_assert_eq(error_arguments(argc[2], argv_1), -1);
	cr_assert_eq(error_arguments(argc[1], argv_1), 0);
	cr_assert_eq(error_arguments(argc[0], argv_2), -1);
}
