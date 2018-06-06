/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_reaction_two
*/

#include "../../include/sbml.h"

int get_stoich(sbml_t *p, int i, int j)
{
	int x = 0;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "stoichiometry=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			p->i.r[j].quantity = atoi(p->sbml[i][x + 1]);
		}
	}
	return (j);
}

int r_stcho(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++)
		if (strcmp(p->sbml[i][x], "species=") == 0) {
			if (p->sbml[i][x + 1] != NULL &&
				strcmp(p->sbml[i][x + 1],
				p->i.r[j].reactants) == 0) {
				j = get_stoich(p, i, j);
			}
		}
	return (j);
}

int r_get_stoicho(sbml_t *p, int i, int j)
{
	for (; strcmp(p->sbml[i][0], "/listOfReactants") != 0; i++) {
		j = r_stcho(p, i, j);
	}
	return (j);
}

void r_stoichoimetry(sbml_t *p, int j)
{
	int i[4] = {0, 0, 0, 0};

	p->i.r[j].quantity = 0;
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "listOfReactants") == 0)
			j = r_get_stoicho(p, i[0], j);
		}
}