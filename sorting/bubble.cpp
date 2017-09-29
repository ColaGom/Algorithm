#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(int* arr, int n)
{
	int i, j;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n-i; ++j)
		{
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}

}

int main()
{
	int arr[6] = { 3, 1, 2, 6, 4, 9 };
	
	bubble_sort(arr, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%3d", arr[i]);
	}
	puts("");
}