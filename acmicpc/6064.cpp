#include <iostream>
#include <vector>

using namespace std;

int get_lcm(int a, int b)
{
	int hcf = a;
	int temp = b;

	while (hcf != temp)
	{
		if (hcf > temp)
			hcf -= temp;
		else
			temp -= hcf;
	}

	return (a * b) / hcf;
}

int main() {
	int t;
	int M, N, x, y;

	cin >> t;

	vector<int> ans = vector<int>(t);

	for (int i = 0; i < t; ++i)
	{
		cin >> M >> N >> x >> y;

		if (x == y) {
			ans[i] = x;
			continue;
		}

		int current = 0;
		int lcm = get_lcm(M, N);

		current = x;

		if (x == M)
			x = 0;

		if (y == N)
			y = 0;

		while (true)
		{
			if (current > lcm) {
				ans[i] = -1;
				break;
			}
			else if ((current % M == x) && (current % N == y))
			{
				ans[i] = current;
				break;
			}

			current += M;
		}
	}

	for (const auto& v : ans)
		printf("%d\n", v);
}

