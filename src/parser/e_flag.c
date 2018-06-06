/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** e_flag
*/

#include "../../include/sbml.h"

void e_flag(sbml_t *p)
{
	int i;

	for (i = 0; p->i.r[i].reactants != NULL; i++) {
		printf("%i %s", p->i.r[i].quantity, p->i.r[i].reactants);
		if (p->i.r[i + 1].reactants != NULL)
			printf(" + ");
	}
	(p->r == 1) ? printf(" <-> ") : printf(" -> ");

	for (i = 0; p->i.p[i].products != NULL; i++) {
		printf("%i %s", p->i.p[i].quantity, p->i.p[i].products);
		if (p->i.p[i + 1].products != NULL)
			printf(" + ");
	}
	printf("\n");
	free_everything(p);
}