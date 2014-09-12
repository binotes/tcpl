#include <ctype.h>
#include <math.h>
#include <stdio.h>
/* function atof: convert string (char s[]) into double float. */

void trim(char s[], char t[])
{
	int i,j;
	for (i=0, j=0; s[i] != '\0'; i++)
	{
		if (isspace(s[i]))
			;
		else {
			t[j++] = s[i];
		}
	}
	t[j] = '\0';
}


void trim_self(char s[])
{
	int i,j;
	for (i=0, j=0; s[i] != '\0'; i++)
	{
		if (isspace(s[i]))
			;
		else {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}

double atof_simple(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-' ? -1 : 1);
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}

double atof(char s[])
{
	double val, power, expon;
	int i, sign, expon_sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-' ? -1 : 1);
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E'){
		i++;
		expon_sign = (s[i] == '-' ? -1 : 1);
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (expon = 0.0; isdigit(s[i]); i++)
			expon = 10.0 * expon + (s[i] - '0');
		expon = expon_sign * expon;
	}
	else {
		expon = 0.0;
	}

	power /= pow(10.0, expon);
	return sign * val / power;
}

int main(void)
{
	char s[] = "  -  1 2 123455.67";
	char t[100];
	trim_self(s);
	printf("%s\n", s);
	// trim(s,t);
	double result =atof(s);
	printf("%f\n", result);
	return 0;
}