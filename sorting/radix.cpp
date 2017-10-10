#include <iostream>
#include <vector>

using namespace std;

void radix_sort(int* data, int p, int k)
{
	int *arr_count, *temp;
	int size;

	size = sizeof(data) / sizeof(int);

	arr_count = (int *)malloc(sizeof(int) * k);
	temp = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < p; ++i)
	{
		memset(arr_count, 0, sizeof(arr_count));

		int digit = (int)pow(k, i);
		
		for (int j = 0; j < size; ++j)
		{
			int cur = data[j] / digit;

			arr_count[cur]++;
		}
	}
}

int main()
{
	int arr[6] = { 33, 111, 22, 63, 4, 9 };

	memset(arr, 0, sizeof(arr));

	

	radix_sort(arr, 3, 10);

	for (int i = 0; i < 6; ++i)
	{
		printf("%5d", arr[i]);
	}
	puts("");
}