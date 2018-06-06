/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** i_flag
*/

#include "../../include/sbml.h"

int i_flag(sbml_t *p)
{
	if (p->i.i.c == 1) {
		compartment(p);
		return (0);
	}
	if (p->i.i.r == 1) {
		reaction(p);
		return (0);
	}
	if (p->i.i.s == 1) {
		species(p);
		return (0);
	}
	generic(p);
	return (0);
}