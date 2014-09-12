#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
	int c, i, nc, nl, nw, state;

	nc = nl = nw = 0;
	state = OUT;

	while ( (c=getchar()) != EOF)
	{
		nc++;
		if (c == '\n') 
			nl++;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT)
		{
			nw++;
			state = IN;
		}
	}
	printf("%d  line %d word %d charactor.\n", nl, nw, nc);
}