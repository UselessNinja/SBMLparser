/*
** EPITECH PROJECT, 2018
** SYN_SBMLparser_2017
** File description:
** requirement
*/

#include <stdlib.h>
#include <unistd.h>

int my_strlen(char const *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}

int is_alphanum(char c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (0);
	return (1);
}

char **my_str_to_word_array_synthesis(char const *str)
{
	int i[3] = {0, 0, 0};
	char **tab = malloc(sizeof(char **) * (my_strlen(str) + 2));

	for (i[2] = 0; str[i[0]] != '\0'; i[2]++) {
		if (is_alphanum(str[i[0]]) != 1) {
			tab[i[2]] = malloc(sizeof(str));
			for (i[1] = 0; is_alphanum(str[i[0]]) != 1; i[1]++) {
				tab[i[2]][i[1]] = str[i[0]];
				i[0]++;
			}
			tab[i[2]][i[1]] = '\0';
			i[1]++;
			i[0] = (str[i[0]] != '\0') ? i[0]++ : i[0];
		} else {
			i[0]++;
			i[2]--;
		}
	}
	tab[i[2]] = NULL;
	return (tab);
}