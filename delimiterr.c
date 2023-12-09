#include "shell.h"
/**
 * tokenization - Splits a string using delimeters
 *
 * @str: string to split
 * @delimm: Delimiter to separate string
 * Return: pointer to the splited string
 */
char **tokenization(char *str, const char *delimm)
{
	unsigned int cur, new;
	char **wordd, **temp, *tok;

	cur = sizeof(char *);
	wordd = malloc(old);
	if (wordd != NULL)
	{
		new = 1;
		tok = strtok(str, delimm);
		while (token)
		{
			if (tok[0] == '#')
				break;
			temp = _realloc(wordd, cur, (new + 1) * sizeof(char *));
			cur = (new + 1) * sizeof(char *);
			if (temp == NULL)
				break;
			wordd = temp;
			++new;

			wordd[new - 2] = malloc(_strlen(tok) + 1);
			if (wordd == NULL)
			{
				free(wordd);
				free(temp);
			}

			if (wordd[new - 2] != NULL)
			{
				_strcpy(wordd[new - 2], tok);
			}
			tok = strtok(NULL, delimm);
			temp = NULL;
		}
		wordd[new - 1] = NULL;
	}
	return (wordd);
}

/**
 * Fusion - merges words with a delimitar
 *
 * @1st: Word1
 * @2nd: Word2
 * @3rd: Word3
 * @delimm: Separator
 * Return: merged string
 */
char *Fusion(char *1st, char *2nd, char *3rd, const char *delimm)
{
	int 1st_size, 2nd_size2, 3rd_size, delimm_size;
	char *merge;

	1st_size = 2nd_size = 3rd_size = delimm_size = 0;

	if (2nd != NULL)
		2ndsize = _strlen(2nd);
	else
		2nd = "";

	if (1st != NULL)
		1st_size = _strlen(1st);
	else
		1st = "";

	if (3rd != NULL)
		3rdsize = _strlen(3rd);
	else
		3rd = "";

	if (delimm != NULL)
		delimm_size = _strlen((char *)delimm);
	else
		delimm = "";

	merge = malloc(size1 + del_size + size2 + del_size + size3 + 2);
	if (merge == NULL)
	{
		return (NULL);
	}
	merge = _strcpy(merge, 1st);
	merge = _strcat(merge, (char *)delimm);
	merge = _strcat(merge, 2nd);
	merge = _strcat(merge, (char *)delimm);
	merge = _strcat(merge, 3rd);
	merge = _strcat(merge, "\n");

	return (merge);
}
