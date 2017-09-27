#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, k;

	cin >> t;

	int solve[15][14];

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 14; ++j)
		{
			if (i == 0)
				solve[i][j] = j + 1;
			else if (j == 0)
				solve[i][j] = 1;
			else
				solve[i][j] = solve[i - 1][j] + solve[i][j-1];
		}
	}

	vector<int> ans = vector<int>(t);

	for (int i = 0; i < t; ++i)
	{
		cin >> k >> n;
		ans[i] = solve[k][n - 1];
	}

	for (const auto& v : ans)
	{
		printf("%d\n", v);
	}
}