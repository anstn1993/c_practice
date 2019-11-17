#include <string.h>
#include <stdio.h>

int main(void)
{
	char msg[] = ",. Hi, there. Hello, Bye";
	const char delims[] = ",. ";

	char* token = strtok(msg, delims);
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, delims);
	}
}