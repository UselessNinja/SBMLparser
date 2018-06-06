/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** read
*/

#include "../../include/sbml.h"

void file_to_tab(char **file, sbml_t *p, int size)
{
	int i = 0;
	p->sbml = malloc(sizeof(char**) * (size + 1));

	for (i = 0; i < size; i++)
		p->sbml[i] = my_str_to_word_array(file[i]);
	p->sbml[i] = NULL;
}

void readfile(sbml_t *p)
{
	int i = 0;
	int r;
	char *buffer = NULL;
	char **file;
	size_t len = 0;

	p->fp = fopen(p->arg[1], "r");
	if (!p->fp)
		exit(84);
	file = malloc(sizeof(char **) * getsize(p->fp));
	do {
		r = getline(&buffer, &len, p->fp);
		file[i] = strdup(buffer);
		i++;
	} while (r != -1);
	file_to_tab(file, p, i);
	file[i] = NULL;
	free_file(file);
	fclose(p->fp);
	p->lines = i;
}