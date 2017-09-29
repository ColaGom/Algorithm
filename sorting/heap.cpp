#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& v, int n, int h)
{
	int max = h;
	int l = 2 * h + 1;
	int r = 2 * h + 2;

	if (l < n && v[l] > v[max])
		max = l;

	if (r < n && v[r] > v[max])
		max = r;

	if (max != h)
	{
		swap(v[h], v[max]);
		heapify(v, n, max);
	}
}

void heap_sort(vector<int>& v)
{
	int n = v.size();

	for (int i = n / 2; i-->0;)
		heapify(v, n, i);

	for (int i = n; i-->0;)
	{
		swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}


int main()
{
	int n;
	cin >> n;
	vector<int> v = vector<int>(n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);

	heap_sort(v);

	for (const auto& i : v)
		printf("%d\n", i);
}