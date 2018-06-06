/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_reaction_three
*/

#include "../../include/sbml.h"

int p_get_stoich(sbml_t *p, int i, int j)
{
	int x = 0;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "stoichiometry=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			p->i.p[j].quantity = atoi(p->sbml[i][x + 1]);
		}
	}
	return (j);
}

int p_stcho(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++)
		if (strcmp(p->sbml[i][x], "species=") == 0) {
			if (p->sbml[i][x + 1] != NULL &&
				strcmp(p->sbml[i][x + 1],
				p->i.p[j].products) == 0) {
				j = p_get_stoich(p, i, j);
			}
		}
	return (j);
}

int p_get_stoicho(sbml_t *p, int i, int j)
{
	for (; strcmp(p->sbml[i][0], "/listOfProducts") != 0; i++) {
		j = p_stcho(p, i, j);
	}
	return (j);
}

void p_stoichoimetry(sbml_t *p, int j)
{
	int i[4] = {0, 0, 0, 0};
	
	p->i.p[j].quantity = 0;
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "listOfProducts") == 0)
			j = p_get_stoicho(p, i[0], j);
		}
}