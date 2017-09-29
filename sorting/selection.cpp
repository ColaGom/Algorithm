#include <iostream>

#define SIZE 10

using namespace std;

void selection_sort(int* arr, int n)
{
	int i, j, min;

	for (int i = 0; i < n; ++i)
	{
		min = i;

		for (int j = i+1; j < n; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}

}

int main()
{
	int arr[SIZE] = { 3, 1, 2, 6, 4, 9, 7, 5, 21, 11 };

	selection_sort(arr, SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%3d", arr[i]);
	}
	puts("");
}