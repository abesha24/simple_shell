#include <unistd.h>
#include <stdio.h>

int main(void)
{
	extern char **environ;
	int d = 0;

	while(environ[d])
	{
		printf("%s\n", environ[d++]); 
	}
	return (0);
}
