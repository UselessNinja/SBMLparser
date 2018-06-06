/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_compartment
*/

#include "../../include/sbml.h"

int hunt_for_the_name(sbml_t *p, int x, int i, int j)
{
	for (x = 0; p->sbml[i][x] != NULL; x++)
		if (p->sbml[i][x + 1] != NULL
			&& strcmp(p->sbml[i][x], "name=") == 0) {
			p->i.c.species[j] = p->sbml[i][x + 1];
			x++;
			while (p->sbml[i][x + 1] != NULL
				&& strchr(p->sbml[i][x + 1], '=') == NULL) {
					p->i.c.species[j] =
					my_strcat_dup(
					my_strcat_dup(p->i.c.species[j], " "),
					p->sbml[i][x + 1]);
			x++;
			}
			j++;
		}
	return (j);
}

int is_it_legal(sbml_t *p, int i, int j)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "compartment=") == 0) {
			if (p->sbml[i][x + 1] != NULL
				&& strcmp(p->sbml[i][x + 1], p->id) == 0) {
				j = hunt_for_the_name(p, x, i, j);
			}
		}
	}
	return (j);
}

void compartment(sbml_t *p)
{
	int i[4] = {0, 0, 0, 0};

	p->i.c.species = malloc(sizeof(char **) * p->lines);
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "species") == 0) {
			i[1] = is_it_legal(p, i[0], i[1]);
		}
	}
	p->i.c.species[i[1]] = NULL;
}