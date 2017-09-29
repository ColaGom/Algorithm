#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(int* arr, int n)
{
	int current = 0 , i;

	while (++current < n)
	{
		for (int i = 0; i < current; ++i)
		{
			if (arr[current] < arr[i])
			{
				int pick = arr[current];
				memcpy(arr + i + 1, arr + i, sizeof(int) * (current - i));
				arr[i] = pick;
				break;
			}
		}
	}
}

int main()
{
	int arr[6] = { 3, 1, 2, 6, 4, 9 };
	
	insertion_sort(arr, 6);

	for (int i = 0; i < 6; ++i)
	{
		printf("%3d", arr[i]);
	}
	puts("");
}