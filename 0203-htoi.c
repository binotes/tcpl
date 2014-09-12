#include <stdio.h>
#include "mytcpllib.h"

int main(void)
{
/*
	char hex[100];
	printf("input a hex string...\n");
	scanf("%s",hex);
	printf("%s = %d\n", hex, htoi(hex) );
*/
	char s[100];
	char c;
	printf("a string pls...\n");
	scanf("%s", s);
	printf("a char pls ok?\n");
	getchar();
	c = getchar();
	squeeze(s,c);
	printf("%s %c\n", s, c );

	return 0;
}