/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** id
*/

#include "../../include/sbml.h"

void is_the_id_here_c(sbml_t *p, int i)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "id=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			if (strcmp(p->sbml[i][x + 1], p->id) == 0) {
				p->i.i.c = 1;
				p->i.i.r = 0;
				p->i.i.s = 0;
			}
		}
	}
}

void is_the_id_here_s(sbml_t *p, int i)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "id=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			if (strcmp(p->sbml[i][x + 1], p->id) == 0) {
				p->i.i.c = 0;
				p->i.i.s = 1;
				p->i.i.r = 0;
			}
		}
	}
}

void is_the_id_here_r(sbml_t *p, int i)
{
	int x;

	for (x = 0; p->sbml[i][x] != NULL; x++) {
		if (strcmp(p->sbml[i][x], "id=") == 0
			&& p->sbml[i][x + 1] != NULL) {
			if (strcmp(p->sbml[i][x + 1], p->id) == 0) {
				p->i.i.c = 0;
				p->i.i.s = 0;
				p->i.i.r = 1;
			}
		}
	}
}

void scan_id(sbml_t *p)
{
	int i[4] = {0, 0, 0, 0};

	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		if (strcmp(p->sbml[i[0]][0], "compartment") == 0) {
			is_the_id_here_c(p, i[0]);
		}
		if (strcmp(p->sbml[i[0]][0], "reaction") == 0) {
			is_the_id_here_r(p, i[0]);
			if (strcmp(p->sbml[i[0]][2], "true") == 0)
				p->r = 1;
		}
		if (strcmp(p->sbml[i[0]][0], "species") == 0) {
			is_the_id_here_s(p, i[0]);
		}
	}
}