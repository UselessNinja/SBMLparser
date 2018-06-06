/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** help
*/

#include "../../include/sbml.h"

void help(void)
{
	printf("USAGE\n");
	printf("\t./SBMLparser SMBLfile [-i ID [-e]] [-json]\n\n");
	printf("DESCRIPTION\n");
	printf("\tSBMLfile\tSBMLfile\n");
	printf("\t-i ID \t\tID of the compartment, reaction or product to be");
	printf(" extracted\n");
	printf("\t\t\t(ignored if uncorrect)\n");
	printf("\t-e\t\tprint the equation if a reaction ID is given as");
	printf("argument\n");
	printf("\t\t\t(ignored otherwise)\n");
	printf("\t-json\t\ttransform the file into a JSON file\n");
	exit(0);
}