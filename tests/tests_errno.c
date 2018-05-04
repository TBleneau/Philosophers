/*
** EPITECH PROJECT, 2018
** test_errno.c
** File description:
** Created by Thomas BLENEAU
*/

#include <criterion/criterion.h>
#include "philo.h"

Test(test01, error_display)
{
	cr_assert_eq(error_display("./philo", E_ARGS), -1);
	cr_assert_eq(error_display("./philo", E_OPTS), -1);
	cr_assert_eq(error_display("./philo", E_NUMB), -1);
}
