#include <iostream>
#include <vector>

using namespace std;

int main() {
	int H, W, N;
	int t;

	cin >> t;

	vector<int> ans = vector<int>(t);

	for (int i = 0; i < t; ++i)
	{
		cin >> H >> W >> N;

		ans[i] = N % H ? N % H * 100 + (N / H) + 1 : ans[i] = H * 100 + (N / H);
	}

	for(auto it = ans.begin() ; it != ans.end() ; it++)
		printf("%d\n", *it);
}