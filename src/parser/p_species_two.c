/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_species_two
*/

#include "../../include/sbml.h"

int stoich(sbml_t *p, int i, int j)
{
	int x = 0;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "stoichiometry=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			p->i.s[j].quantites = atoi(p->sbml[i][x + 1]);
		}
	}
	return (j);
}