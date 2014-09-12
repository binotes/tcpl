#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#include "mytcpllib.h"

// void shellsort(int v[], int n)
// {
// 	int gap, i, j, temp;

// 	for (gap = n / 2; gap > 0; gap /= 2)
// 		for (i = gap; i < n; i++)
// 			for (j = i-gap; (j >= 0) && (v[j] > v[j+gap]); j -= gap){
// 				temp = v[j];
// 				v[j] = v[j+gap];
// 				v[j+gap] = temp;
// 			}
// }

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int data[], int n)
{
	int k = n - 1;
	while (k >= 0){
		int i,j;
		for(i = 1, j = -1; i <= k; i++)
			if (data[i-1]> data[i]) {
				j = i - 1;
				swap(&data[i], &data[j]);
			}
		k = j;
	}
}

int main(void)
{
	int p[15] = {0};
	FILE *fp;
	char filename[100] = "data_for_sort.txt";
	fp = fopen(filename,"r");
	if (fp == NULL)
		printf("fail to open!\n");
	else {
		int i = 0;
		int data = 0;
		int n;
		while ((n = fscanf(fp, "%d", &p[i++])) == 1)
			;
		fclose(fp);
		}
	shellsort(p,15);
	char filename[100] = "data_sorted.txt";
	fp = fopen(filename,"w");
	if (fp == NULL)
		printf("fail to open!\n");
	else {
		int i;
		for (i = 0; i < ARRAY_SIZE(p); i++)
			fprintf(fp, "%d\n", p[i]);
		fclose(fp);
		}
	int i;
	for (i = 0; i < ARRAY_SIZE(p); i++)
		printf("p[%03d] = %d\n", i, p[i]);
	return 0;
}