#include "shell.h"

/**
 * builtin_exit - Exits the shell
 * @tokens: The command and its arguments
 * @env: The environment variables (unused)
 * Return: The status to exit with
 */
int builtin_exit(char **tokens, char **env)
{
(void) env;
int status = 0;

if (tokens[1])
status = atoi(tokens[1]);

free_tokens(tokens);
exit(status);
}

/**
 * builtin_setenv - Sets an environment variable
 * @tokens: The command and its arguments
 * @env: The environment variables (unused)
 * Return: Always 0 (success)
 */
int builtin_setenv(char **tokens, char **env)
{
(void) env;
if (!tokens[1] || !tokens[2])
{
fprintf(stderr, "Usage: setenv KEY VALUE\n");
return (1);

setenv(tokens[1], tokens[2], 1);
return (0);
}

/**
 * builtin_unsetenv - Unsets an environment variable
 * @tokens: The command and its arguments
 * @env: The environment variables (unused)
 * Return: Always 0 (success)
 */
int builtin_unsetenv(char **tokens, char **env)
{
(void) env;
if (!tokens[1])
{
fprintf(stderr, "Usage: unsetenv KEY\n");
return (1);
}

unsetenv(tokens[1]);
return (0);
}

/**
 * builtin_cd - Changes the current working directory
 * @tokens: The command and its arguments
 * @env: The environment variables (unused)
 * Return: 1 if directory change fails, 0 otherwise
 */
int builtin_cd(char **tokens, char **env)
{
(void) env;
char *path;

if (!tokens[1])
path = getenv("HOME");
else
path = tokens[1];

if (chdir(path) == -1)
{
perror("cd");
return (1);
}

return (0);
}

/**
 * execute_builtin - Executes a builtin command
 * @tokens: The command and its arguments
 * @env: The environment variables (unused)
 * Return: The return value of the builtin command, or -1 if not found
 */
int execute_builtin(char **tokens, char **env)
{
(void) env;
int i;
builtin_pair_t builtins[] = {
{"exit", builtin_exit},
{"setenv", builtin_setenv},
{"unsetenv", builtin_unsetenv},
{"cd",  builtin_cd},
};

for (i = 0; builtins[i].name; i++)
{
if (strcmp(tokens[0], builtins[i].name) == 0)
return (builtins[i].func(tokens, env));
}

return (-1);
}

/**
 * free_tokens - Frees a NULL-terminated array of string tokens
 * @tokens: The array of string tokens to free
 */
void free_tokens(char **tokens)
{
int i;

for (i = 0; tokens[i] != NULL; i++)
{
free(tokens[i]);
}

free(tokens);
}
