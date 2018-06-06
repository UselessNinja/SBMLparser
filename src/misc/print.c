/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** print
*/

#include "../../include/sbml.h"

void print_list(char *str)
{
	int i;

	write(1, "-", 1);
	write(1, "-", 1);
	write(1, "-", 1);
	write(1, ">", 1);
	for (i = 0; i < my_strlen(str); i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
}