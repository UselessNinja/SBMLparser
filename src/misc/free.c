/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** free
*/

#include "../../include/sbml.h"

void free_file(char **map)
{
	int count;

	for (count = 0; map[count] != NULL; count++)
		free(map[count]);
	free(map);
}

void free_sbml(char ***map)
{
	int x;
	int y;

	for (y = 0; map[y] != NULL; y++) {
		for (x = 0; map[y][x] != NULL; x++)
			free(map[y][x]);
		free(map[y]);
	}
	free(map);
}

void free_everything(sbml_t *p)
{
	free_sbml(p->sbml);
	exit(0);
}