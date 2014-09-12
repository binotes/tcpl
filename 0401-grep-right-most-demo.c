
#include <stdio.h>

int strrindex(char s[], char t[]);
int strindex(char s[], char t[]);

int main(void)
{
	char s[] = "here we go . and we goes here. now.";
	char t[] = "go";
	int pos = strrindex(s, t);
	printf("%d\n",  pos);
}

int strrindex(char s[], char t[])

/* return the rightmost index of t in s, -1 if none*/
{
	int i, j, k;
	int pos = -1;

	for (i = 0; s[i] != '\0'; i++){
		for (j=i, k=0; t[k] != '\0', s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i; 
	}
	return pos;
}

int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++){
		for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}