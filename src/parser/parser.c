/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** parser
*/

#include "../../include/sbml.h"

void parser(sbml_t *p)
{
	readfile(p);
	if (p->f.i == 1) {
		scan_id(p);
		i_flag(p);
		i_display(p);
	} else {
		filldata(p);
		letcsorthemall(p->d);
		display(p);
		free_everything(p);		
	}
}