/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** sorting
*/

#include "../../include/sbml.h"

static int comparison(void const *a, void const *b)
{
	const char *pa = *(const char **)a;
	const char *pb = *(const char **)b;

	return (strcmp(pa, pb));
}

static int comparison_two(void const *a, void const *b)
{
	data_t const *pa = a;
	data_t const *pb = b;

	return (strcmp(pa->tag, pb->tag));
}

void letcsorthemall(data_t *d)
{
	int i = 0;
	int j;

	for (i = 0; d[i].tag != NULL; i++) {
		for (j = 0; d[i].attribute[j] != NULL; j++);
		qsort(d[i].attribute, j,
			sizeof(char *), comparison);
	}
	qsort(d, i,
		sizeof(data_t), comparison_two);
}
