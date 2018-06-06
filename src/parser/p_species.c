/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_species
*/

#include "../../include/sbml.h"

int stcho(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++)
		if (strcmp(p->sbml[i][x], "species=") == 0) {
			if (p->sbml[i][x + 1] != NULL
				&& strcmp(p->sbml[i][x + 1], p->id) == 0) {
				j = stoich(p, i, j);
			}
		}
	return (j);
}

int get_stoicho(sbml_t *p, int i, int j)
{
	for (; strcmp(p->sbml[i][0], "/listOfProducts") != 0; i++) {
		j = stcho(p, i, j);
	}
	return (j);
}

void stoichoimetry(sbml_t *p, int j)
{
	int i[4] = {0, 0, 0, 0};

	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "listOfReactants") == 0)
			j = get_stoicho(p, i[0], j);
		}
}

int in_thewild(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++)
		if (strcmp(p->sbml[i][x], "id=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			p->i.s[j].reaction = p->sbml[i][x + 1];
			stoichoimetry(p, j);
			j++;
	}
	return (j);
}

void species(sbml_t *p)
{
	int i[4] = {0, 0, 0, 0};

	p->i.s = malloc(sizeof(s_t) * p->lines);
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "reaction") == 0) {
			i[1] = in_thewild(p, i[0], i[1]);
		}
	}
	p->i.s[i[1]].reaction = NULL;
}