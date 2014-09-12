#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main(void)
{
	printf("input strings..\n");
	char s[100] = "h ";
//	while (scanf("%s",s))
	// {
		printf("%s\n", s);
		int len = trim(s);
		printf("trimmed len %d\n", len );
		if(len > 0)
			printf("after trimmed :%s\n", s);
		else
			printf("it's all of blanks.");
	// }
	return 0;
}

int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
		else
			printf("%d\n", n);

	s[n+1] = '\0';

	return n;
}