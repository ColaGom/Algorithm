#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_answer(int dist)
{
	int l = 0, r = dist;
	int ans = 0;

	for (int i = 1; i < INT_MAX ; ++i)
	{
		if (l == r)
			return ans;

		ans += l+i < r ? 2 : 1;

		if (l + i >= r - i)
			return ans;

		l += i;
		r -= i;
	}
}

int main() {
	int n;
	int a, b;
	int *ans;

	scanf("%d", &n);

	ans = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		ans[i] = get_answer(b - a);
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", ans[i]);
	}
}