/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** main
*/

#include "../include/sbml.h"

void init_flags(sbml_t *p)
{
	p->f.e = 0;
	p->f.h = 0;
	p->f.i = 0;
	p->f.json = 0;
	p->i.i.c = 0;
	p->i.i.r = 0;
	p->i.i.s = 0;	
	p->r = 0;
}

int i_check(sbml_t *p)
{
	int i;

	if (strcmp(p->arg[2], "-i") == 0)
		p->f.i = 1;
	if (strcmp(p->arg[2], "-i") != 0)
		exit(84);
	if (p->arg[3] != NULL)
		p->id = p->arg[3];
	else
		p->id = ";";
	if (p->arg[4] != NULL && strcmp(p->arg[4], "-e") == 0) 
		p->f.e = 1;
	for (i = 3; p->arg[i] != NULL; i++)
		if (strcmp(p->arg[i], "-json") == 0)
			exit(0);
	return (0);
}

int argv(sbml_t *p)
{
	if (strcmp(p->arg[1], "-h") == 0)
		help();
	if (check_extension(p->arg[1], "sbml", 0) == 0)
		exit(84);
	if (p->arg[2] == NULL)
		return (0);
	i_check(p);
	return (0);
}

int main(int ac, char **av)
{
	sbml_t p;

	init_flags(&p);
	if (ac < 2)
		return (84);
	p.arg = av;
	argv(&p);
	parser(&p);
	return (0);
}