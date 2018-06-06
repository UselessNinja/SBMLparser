/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** p_sorting_two
*/

#include "../../include/sbml.h"

static int comparison_three(void const *a, void const *b)
{
	r_t const *pa = a;
	r_t const *pb = b;
	
	return (strcmp(pa->reactants, pb->reactants));
}

static int comparison_four(void const *a, void const *b)
{
	p_t const *pa = a;
	p_t const *pb = b;
	
	return (strcmp(pa->products, pb->products));
}

void sort_r(sbml_t *p)
{
	int a;

	for(a = 0; p->i.r[a].reactants != NULL; a++);
	qsort(p->i.r, a, sizeof(r_t), comparison_three);
	for(a = 0; p->i.p[a].products != NULL; a++);
	qsort(p->i.p, a, sizeof(p_t), comparison_four);
}