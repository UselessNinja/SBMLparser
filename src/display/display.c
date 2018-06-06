/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** display
*/

#include "../../include/sbml.h"

void print_att(char *att)
{
	int i;

	write(1, "-", 1);
	write(1, "-", 1);
	write(1, "-", 1);
	write(1, ">", 1);
	for (i = 0; att[i] != '='; i++)
		write(1, &att[i], 1);
	write(1, "\n", 1);
}

void display(sbml_t *p)
{
	int i;
	int j;

	for (i = 0; p->d[i].tag != NULL; i++) {
		if (strcmp(p->d[i].tag, "xml") != 0) {
			my_putstr(p->d[i].tag);
			my_putchar('\n');
			for (j = 0; p->d[i].attribute[j] != NULL; j++)
				print_att(p->d[i].attribute[j]);
		}
	}
}