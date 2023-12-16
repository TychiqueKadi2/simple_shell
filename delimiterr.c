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
	wordd = malloc(cur);
	if (wordd != NULL)
	{
		new = 1;
		tok = strtok(str, delimm);
		while (tok)
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
 * @Fst: Word1
 * @Snd: Word2
 * @Trd: Word3
 * @delimm: Separator
 * Return: merged string
 */
char *Fusion(char *Fst, char *Snd, char *Trd, const char *delimm)
{
	int Fst_size, Snd_size, Trd_size, delimm_size;
	char *merge;

	Fst_size = Snd_size = Trd_size = delimm_size = 0;

	if (Snd != NULL)
		Snd_size = _strlen(Snd);
	else
		Snd = "";

	if (Fst != NULL)
		Fst_size = _strlen(Fst);
	else
		Fst = "";

	if (delimm != NULL)
		delimm_size = _strlen((char *)delimm);
	else
		delimm = "";

	merge = malloc(Fst_size + delimm_size + Snd_size + delimm_size + Trd_size + 2);
	if (merge == NULL)
	{
		return (NULL);
	}
	merge = _strcpy(merge, Fst);
	merge = _strcat(merge, (char *)delimm);
	merge = _strcat(merge, Snd);
	merge = _strcat(merge, (char *)delimm);
	merge = _strcat(merge, Trd);
	merge = _strcat(merge, "\n");

	return (merge);
}
