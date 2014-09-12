#include <stdio.h>

int main(void)
{
	long nc;

	nc = 0;
	while(getchar() != EOF)
		nc++;
	printf("%ld chars\n", nc);

	return 0;
}