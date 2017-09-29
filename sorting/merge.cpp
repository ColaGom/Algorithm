#include <iostream>

#define SIZE 10

using namespace std;

void merge(int* arr, int l, int r,int m)
{
	int *L, *R;
	int ls = m-l+1, rs = r-m;

	L = (int*)malloc(sizeof(int) * ls);
	R = (int*)malloc(sizeof(int) * rs);

	memcpy(L, arr + l, sizeof(int) * ls);
	memcpy(R, arr + m + 1, sizeof(int) * rs);

	int li = 0, ri = 0, k = l;

	while (li < ls && ri < rs)
	{
		if (L[li] < R[ri])
		{
			arr[k++] = L[li];
			li++;
		}
		else
		{
			arr[k++] = R[ri];
			ri++;
		}
	}

	while (li < ls)
		arr[k++] = L[li++];

	while (ri < rs)
		arr[k++] = R[ri++];
}

void merge_sort(int* arr, int l,int r)
{
	if (l < r)
	{
		int m = (r - l) / 2 + l;

		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		merge(arr, l, r, m);
	}
}

int main()
{
	int arr[SIZE] = { 3, 1, 2, 6, 4, 9, 7, 5, 21, 11 };

	merge_sort(arr, 0, SIZE-1);

	for (int i = 0; i < SIZE; ++i)
	{
		printf("%3d", arr[i]);
	}
	puts("");
}