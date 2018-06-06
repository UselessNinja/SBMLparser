/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_reaction
*/

#include "../../include/sbml.h"

int get_product(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; strcmp(p->sbml[i][0], "/listOfProducts") != 0; i++) {
		for (x = 0; p->sbml[i][x] != NULL; x++)
			if (strcmp(p->sbml[i][x], "species=") == 0
				&& p->sbml[i][x + 1] != NULL) {
				p->i.p[j].products = p->sbml[i][x + 1];
				p_stoichoimetry(p, j);
				j++;
			}
	}
	return (j);
}

int get_reactants(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; strcmp(p->sbml[i][0], "/listOfReactants") != 0; i++) {
		for (x = 0; p->sbml[i][x] != NULL; x++)
			if (strcmp(p->sbml[i][x], "species=") == 0
				&& p->sbml[i][x + 1] != NULL) {
				p->i.r[j].reactants = p->sbml[i][x + 1];
				r_stoichoimetry(p, j);
				j++;
			}
	}
	return (j);
}

void reaction(sbml_t *p)
{
	int i[4] = {0, 0, 0, 0};

	p->i.p = malloc(sizeof(char **) * p->lines);
	p->i.r = malloc(sizeof(char **) * p->lines);
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "listOfReactants") == 0)
			i[1] = get_reactants(p, i[0], i[1]);
	}
	p->i.r[i[1]].reactants = NULL;
	i[1] = 0;
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "listOfProducts") == 0)
			i[1] = get_product(p, i[0], i[1]);
	}
	p->i.p[i[1]].products = NULL;
}