#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop:  get next operator or numeric operand */
int getop(char s[])
{
	int i,c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') /* not digital or not in the mid of a digital*/
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch())) /* s[++i] !! because s[0] has been set to getch()*/
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch())) /* s[++i] */
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}
