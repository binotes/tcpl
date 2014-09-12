#include <stdio.h>
#include "mytcpllib.h"

int main(void)
{
	char s[100] = "hello";
	char t[] = " world";
	strcat(s,t);
	printf("%s\n", s);
	return 0;
}
