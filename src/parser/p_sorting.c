/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_sorting
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
	s_t const *pa = a;
	s_t const *pb = b;
	
	return (strcmp(pa->reaction, pb->reaction));
}

void sort_cg(sbml_t *p)
{
	int j;

	for (j = 0; p->i.c.species[j] != NULL; j++);
	qsort(p->i.c.species, j, sizeof(char *), comparison);
}

void sort_s(sbml_t *p)
{
	int i;

	for(i = 0; p->i.s[i].reaction != NULL; i++);
	qsort(p->i.s, i, sizeof(s_t), comparison_two);
}