#include <iostream>
#include <vector>

using namespace std;

void radix_sort(int* data, int size, int p,int k)
{
	int *counts, *temp; 
	int index, pval, i, j, n;
	if ((counts =
		(int*)malloc(k * sizeof(int))) == NULL)
		return;
	if ((temp = (int*)malloc(size * sizeof(int))) == NULL)
		return;
	for (n = 0; n < p; n++) {
		for (i = 0; i < k; i++)
			counts[i] = 0;

		pval = (int)pow((double)k, (double)n);

		for (j = 0; j < size; j++) {
			index = (int)(data[j] / pval) % k;
			counts[index] = counts[index] + 1;
		}

		for (i = 1; i < k; i++) {
			counts[i] = counts[i] + counts[i - 1];
		}

		for (j = size - 1; j >= 0; j--) {
			index = (int)(data[j] / pval) % k;
			temp[counts[index] - 1] = data[j];
			counts[index] = counts[index] - 1;
		}

		memcpy(data, temp, size * sizeof(int));
	}
}

int main()
{
	int arr[6] = { 33, 111, 22, 63, 4, 9 };

	radix_sort(arr, 6, 3, 10);

	for (int i = 0; i < 6; ++i)
	{
		printf("%5d", arr[i]);
	}
	puts("");
}