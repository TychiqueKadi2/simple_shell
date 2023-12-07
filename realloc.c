#include "shell.h"
/**
 * _realloc - Reallocates memory
 * @ptr: pointer to the old memory allocated
 * @cur_size: current size of memory
 * @new_size: new allocated memory size
 * Return: pointer to new allocated memory
 */
void *_realloc(void *ptr, unsigned int cur_size, unsigned int new_size)
{
	char *point;
	unsigned int i, sizee = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		point = malloc(new_size);
		return (point);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == cur_size)
		return (ptr);

	point = malloc(new_size);
	if (point == NULL)
		return (NULL);
	if (new_size > cur_size)
		sizee = cur_size;
	for (i = 0; i < sizee; i++)
		point[i] = oldp[i];
	free(ptr);
	return (point);
}
