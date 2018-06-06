/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** get_size
*/

#include "../../include/sbml.h"

int getsize(FILE *fp)
{
	int size;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return (size);
}