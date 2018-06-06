/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** cmp_args
*/

#include "my.h"

int check_extension(char *arg, char *ext, size_t len)
{
	char *temp = strrchr(arg, '.');

	if (temp != NULL) {
		if (len == 0)
			len = strlen(ext);
		return (strncmp(temp + 1, ext, len) == 0);
	}
	return (0);
}