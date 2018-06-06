/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** i_display
*/

#include "../../include/sbml.h"

void display_g(sbml_t *p)
{
	int x;

	my_putstr("List of species\n");
	for (x = 0; p->i.c.species[x] != NULL; x++)
		print_list(p->i.c.species[x]);
}

void display_s(sbml_t *p)
{
	int x;

	my_putstr("List of reactions consuming species ");
	my_putstr(p->id);
	my_putstr(" (quantities)\n");
	for (x = 0; p->i.s[x].reaction != NULL; x++)
		printf("--->%s (%i)\n",
			p->i.s[x].reaction, p->i.s[x].quantites);
}

void display_r(sbml_t *p)
{
	int x;

	my_putstr("List of reactants of reaction ");
	my_putstr(p->id);
	my_putchar('\n');
	for (x = 0; p->i.r[x].reactants != NULL; x++)
		print_list(p->i.r[x].reactants);
	my_putstr("List of products of reaction ");
	my_putstr(p->id);
	my_putchar('\n');
	for (x = 0; p->i.p[x].products != NULL; x++)
		print_list(p->i.p[x].products);
}

void display_c(sbml_t *p)
{
	int x;

	my_putstr("List of species in compartment ");
	my_putstr(p->id);
	my_putchar('\n');
	for (x = 0; p->i.c.species[x] != NULL; x++)
		print_list(p->i.c.species[x]);
}

void i_display(sbml_t *p)
{
	if (p->i.i.c == 1) {
		sort_cg(p);
		display_c(p);
		free_everything(p);
	}
	if (p->i.i.r == 1) {
		sort_r(p);
		if (p->f.e == 1)
			e_flag(p);
		display_r(p);
		free_everything(p);
	}
	if (p->i.i.s == 1) {
		sort_s(p);
		display_s(p);
		free_everything(p);
	}
	sort_cg(p);
	display_g(p);
	free_everything(p);
}