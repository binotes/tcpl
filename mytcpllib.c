#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "mytcpllib.h"
#define YES 1
#define NO  0

int mystrlen(const char s[]){
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;

	return i;
}

int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim>0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
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

void squeeze(char s[], int c){
	int i, j;

	for (i=j=0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0,j = mystrlen(s)-1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void strcat(char s[], char t[]) /*assume s[] is big enough*/
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t[] to s[]*/
		;
}
/*
 * converting between different base
 *
 */


int atoi(char s[])
{
	int i, n;

	n = 0;
	for(i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + (s[i] - '0');
	return n;
}

int htoi(char s[])
{
	int hexdigit, i, inhex, n;

	i = 0;
	if(s[i] == '0'){
		i++;
		if(s[i] =='x' || s[i] == 'X')
			i++;
	}
	n = 0;
	inhex = YES;
	for ( ; inhex == YES; i++){
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <='z')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			hexdigit = s[i] - 'Z' + 10;
		else
			inhex = NO;
		if (inhex == YES)
			n = 16 * n + hexdigit;
	}
	return n;
}

double atof(char s[])
{
	double val, power, exponent;
	int i, sign, exponent_sign;

	for (i = 0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
		exponent_sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exponent = 0.0; isdigit(s[i]); i++)
			exponent = 10.0 * exponent + (s[i] - '0');
		exponent = exponent_sign * exponent;
	} else {
		exponent = 0.0;
	}
	power /= pow(10.0, exponent);
	return sign * val / power;
}

int testctags(void){
	return 0;
}
/* sort */
void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i-gap; (j >= 0) && (v[j] > v[j+gap]); j -= gap){
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
}