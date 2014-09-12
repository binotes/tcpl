#include <stdio.h>

int atoi(char s[]);

int main(void)
{
	int i = 0;
	char s[] = "hello w orld.\n\0";
	while (s[i] != '\0')
	{
		printf("%d\n", s[i]);
		// printf("%c\n", s[i]);
		i++;
	}
	char s_i[] = "1234567";
	int result =atoi(s_i);
	printf("%d\n", result);
	return 0;
}


int atoi(char s[])
{
	int i, n;

	n = 0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + (s[i] - '0');
	return n;
}