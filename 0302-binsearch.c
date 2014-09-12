#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

int binsearch(int x, int v[], int n);

int main(void)
{
	int s[10] = {1,3,5,7,9,11,45,47,89,100};
	int i = 10;
	int result = binsearch(10,s,ARRAY_SIZE(s));
	printf("%d\n", result);


	return 0;
}
/* @binotes: ``high = mid + 1'' should be ``high = mid - 1'', or dead loop */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1; 
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;

	}
	return -1;
}