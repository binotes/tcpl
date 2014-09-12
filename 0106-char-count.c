#include <stdio.h>

int main(void)
{
	int c, i, nwhite, nother;
	int nchar[52];

	nwhite = nother = 0;
	for(i = 0; i< 52; i++)
		nchar[i] = 0;

	while ((c = getchar()) != EOF)
		if ( c >= 'A' && c <= 'Z')
			nchar[c-'A']++;
		else if ( c >= 'a' && c <= 'z')
			nchar[c-'a'+26]++;
		else if ( c == ' ' || c == '\t' || c == '\n' )
			nwhite++;
		else
			nother++;

	printf("char = \n");
	c = 'A';
	for (i = 0; i < 26; i++)
		printf("%c", c++);
	c = 'a';
	for (i = 0; i < 26; i++)
		printf("%c", c++);
	printf("\n");
	for (i = 0; i < 52; i++)
		printf("%d",  nchar[i]);
	printf(", white space = %d, other = %d .\n", nwhite, nother);

	return 0;
}