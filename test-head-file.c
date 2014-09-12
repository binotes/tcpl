#include <stdio.h>
#include <string.h>
#include "mytcpllib.h"
#define MAX 80


int main(void)
{
	char list[MAX];

	int i;
	char c;

	for(i = 0; i < MAX; i++)
	{
		if ((c = getchar()) == '\n')
			break;
		else
			list[i] = c;
	}
	list[i] = '\0';
	// i = 0;
	// while (list[i] != '\0')
	// 	{printf("%c", list[i]); i++;}
	printf("\n");
	printf("%d\n", mystrlen(list));
	printf("%d\n", strlen(list));
}