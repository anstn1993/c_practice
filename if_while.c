#include <stdio.h>

int main(void)
{
	int counter = 5;
	while (counter >= 0) {
		if (counter) {
			printf("Hello world\n");
		}
		else {
			printf("Goodbye world\n");
		}
		--counter;
	}
	return 0;
}
