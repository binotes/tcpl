#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, a, b;
	a = 9;
	b = 0;
	n = -1;
	int z = -1;
	if (n > 0)
	{
		if (a > b)
			z = a;
	/*else matches the nearest "if" */
	}
		else 
			z = b;

	printf("%d\n", z);
	/* code */
	return 0;
}