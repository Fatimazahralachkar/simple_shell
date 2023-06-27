#include "header.h"


/**
 * print_linked_list - Print linked list
 * @head: Head of the linked list
 * Owned by: Imane & Fatima Zahra
 * Return: Size of the linked list
 */
size_t print_linked_list(list_t *head)
{
	list_t *current = head;
	int count = 0;
	int len = 0;

	if (head == NULL)
		return (0);

	while (current != NULL)
	{
		if (current->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			len = 0;
			while ((current->var)[len] != '\0')
				len++;
			write(STDOUT_FILENO, current->var, len);
			write(STDOUT_FILENO, "\n", 1);
		}
		current = current->next;
		count++;
	}

	return (count);
}


/**
 * add_node_at_end - Add a node to the end of a linked list
 * @head: Pointer to the head of the linked list
 * @str: Data for the new node
 * Owned by: Imane @ gatima Zahra
 * Return: Pointer to the updated linked list
 */
list_t *add_node_at_end(list_t **head, char *str)
{
	list_t *new_node, *current;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->var = custom_strdup(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	return (*head);
}

/**
 * delete_node_at_index - Delete a node at a given index in a linked list
 * @head: Pointer to the head of the linked list
 * @index: Index of the node to be deleted
 * Owned by: Imane & Fatima Zahra
 * Return: 1 if successful, -1 if failed
 */
int delete_node_at_index(list_t **head, int index)
{
	list_t *current, *temp;
	int count = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->var);
		free(temp);
		return (1);
	}

	current = *head;
	while (count < index - 1)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
		count++;
	}

	temp = current->next;
	current->next = temp->next;
	free(temp->var);
	free(temp);

	return (1);
}



/**
 * free_linked_list - Frees a linked list
 * @list: Linked list to be freed
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void free_linked_list(list_t *list)
{
	list_t *current, *temp;

	current = list;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->var);
		free(temp);
	}
}

/**
 * env_linked_list - Creates a linked list from environmental variables
 * @env: Environmental variables
 * Return: Linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *head = NULL;
	int i = 0;

	while (env[i] != NULL)
	{
		add_node_at_end(&head, env[i]);
		i++;
	}
	return (head);
}

