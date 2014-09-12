#ifndef mytcpllib_h_
#define mytcpllib_h_


enum months
{
	JAN = 1, FEB, MAR, APP, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

int mystrlen(const char s[]);
int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);
void trim(char s[], char t[]);
void trim_self(char s[]);
void squeeze(char s[], int c);
void reverse(char s[]);
// int trim(char s[]);
void strcat(char s[], char t[]);

int atoi(char s[]);
int htoi(char s[]);
double atof(char s[]);

int testctags(void);
/* sort */
void shellsort(int v[], int n);


#endif