#include <ctype.h>
#include <stdio.h>

int atoi(char s[])
{
	int i, n, sign;

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(n = 0; isdigit(s[i]); i++)
		n = 10 * n  + s[i] - '0';

	return sign * n;
}

int main(void)
{
	printf("a digital string please...\n");
	char p[100];
	scanf("%s", p);
	int result = atoi(p);
	printf("%d\n", result);

	return 0;
}