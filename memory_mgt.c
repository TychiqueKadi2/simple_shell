#include "shell.h"
/**
 * free_pointer - Helps to free a pointer
 *
 * @pointer: Pointer to free
 * Return: void
 **/
void free_pointer(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
	pointer = NULL;
}

/**
 * free_doublepointer - Helps free a double pointer
 *
 * @pointer: Double pointer to free
 * Return: none
 **/
void free_doublepointer(void **pointer)
{
	void **temp;

	for (temp = pointer; *temp != NULL; temp++)
	{
		free_pointer(*temp);
	}

	free_pointer(pointer);
}
