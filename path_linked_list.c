#include <shell.h>

/**
 * env_linked_list - creates a linked list from environmental variables
 * @env: environmental variables
 * Return: linked list
 */
list_t *env_linked_list(char **env)
{
	list_t *h;//h - head
	int d = 0;

	h = NULL;
	while (env[d] != NULL)
	{
		add_end_node(&h, env[d]);
		d++;
	}
	return (h);
}

int main(void)
{
	list_t *h;

	h = NULL;
	char p[12] = "PATH";
	char *path = p;
	env_linked_list(**path);
	print_list(h);
	return (0);
	}
