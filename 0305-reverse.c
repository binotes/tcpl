#include <stdio.h>
#include <string.h>

/* reverse string s in place*/
void reverse(char s[])
{
	int c, i, j;
	for (i = 0,j = strlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main(void)
{
	char s[100];
	int i = 0;
	printf("input a string\n");
	scanf("%s", s);
	while(s[i])
		printf("%c", s[i++]);
	printf("\n");
	reverse(s);
	i = 0;
	while(s[i])
		printf("%c", s[i++]);
	printf("\n");

	return 0;
}