#include <stdio.h>

#define IN 1
#define OUT 0

int mian(void)

int main(void)
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		nc++;
		if (c == '\n') 
			nl++;
		if (c == '\n' || c == '\t' || c ==' ')
			state = OUT;
		else if (state == OUT){
			state = IN;
			nw++;
		}
	}
	printf("%d  line %d word %d charactor.\n", nl, nw, nc);

	return 0;
}