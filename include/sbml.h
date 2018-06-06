/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** sbml
*/

#ifndef SBML_H_
#define SBML_H_

#include "../lib/my/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct c_s {
	char **species;
} c_t;

typedef struct s_s {
	char *reaction;
	int quantites;
} s_t;

typedef struct r_s {
	char *reactants;
	int quantity;
} r_t;

typedef struct p_s {
	char *products;
	int quantity;	
} p_t;

typedef struct i_s {
	int c;
	int s;
	int r;
} i_t;

typedef struct i_flag_s {
	i_t i;
	c_t c;
	s_t *s;
	r_t *r;
	p_t *p;
} i_flag_t;

typedef struct data_s {
	int pt;
	char *tag;
	char **attribute;
} data_t;

typedef struct flag_s {
	int i;
	int e;
	int json;
	int h;
} flag_t;

typedef struct sbml_s {
	flag_t f;
	data_t *d;
	FILE *fp;
	int lines;
	int r;
	char *id;
	char **arg;
	char ***sbml;
	i_flag_t i;
} sbml_t;

void help(void);
void parser(sbml_t *p);
void readfile(sbml_t *p);
int getsize(FILE *fp);
void filldata(sbml_t *p);
void letcsorthemall(data_t *p);
void display(sbml_t *p);
void free_everything(sbml_t *p);
void free_file(char **map);
void compartment(sbml_t *p);
void reaction(sbml_t *p);
void species(sbml_t *p);
void generic(sbml_t *p);
void scan_id(sbml_t *p);
int i_flag(sbml_t *p);
void i_display(sbml_t *p);
void sort_cg(sbml_t *p);
void sort_r(sbml_t *p);
void sort_s(sbml_t *p);
int stoich(sbml_t *p, int i, int j);
void print_list(char *str);
void r_stoichoimetry(sbml_t *p, int j);
void p_stoichoimetry(sbml_t *p, int j);
void e_flag(sbml_t *p);

#endif /* !SBML_H_ */
