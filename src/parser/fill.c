/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** fill
*/

#include "../../include/sbml.h"

int checkduplica(sbml_t *p, int x, int y)
{
	int i[4] = {0, 0, 0, 0};

	if (p->d[i[0]].tag == NULL)
		return (0);
	for (i[0] = 0; p->d[i[0]].tag != NULL; i[0]++) {
		if (strcmp(p->sbml[x][y], p->d[i[0]].tag) == 0)
			return (1);
	}
	return (0);
}

void tags(sbml_t *p)
{
	int i[4] = {0, 0, 0, 0};

	p->d = malloc(sizeof(data_t) * (p->lines + 2));
	p->d[0].tag = NULL;
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
			p->d[i[3]].pt = 0;
		if (checkduplica(p, i[0], 0) == 0 &&
			strchr(p->sbml[i[0]][0], '/') == NULL &&
			strstr(p->sbml[i[0]][0], "listOf") == NULL) {
			p->d[i[3]].tag = p->sbml[i[0]][0];
			p->d[i[3]].pt = i[0];
			i[3]++;
			p->d[i[3]].tag = NULL;
		}
	}
}

int *insertatt(sbml_t *p, int *i)
{
	for (i[1] = 0; p->sbml[i[0]][i[1]] != NULL; i[1]++) {
		if (strchr(p->sbml[i[0]][i[1]], '=') != NULL) {
			p->d[i[3]].attribute[i[2]] = malloc(sizeof(char) *
				strlen(p->sbml[i[0]][i[1]]));
			p->d[i[3]].attribute[i[2]] = p->sbml[i[0]][i[1]];
			i[2]++;
		}
	}
	p->d[i[3]].attribute[i[2]] = NULL;
	return (i);
}

void attributes(sbml_t *p)
{
	int *i = malloc(sizeof(int) * 4);

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	for (i[0] = 0; p->sbml[i[0]] != NULL; i[0]++) {
		p->d[i[0]].attribute = malloc(sizeof(char *) * (p->lines + 3));
		if (i[0] == p->d[i[3]].pt) {
			i = insertatt(p, i);
			i[3]++;
			i[2] = 0;
		}
	}
	free(i);
}

void filldata(sbml_t *p)
{
	tags(p);
	attributes(p);
}