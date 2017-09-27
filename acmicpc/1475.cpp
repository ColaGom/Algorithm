#include <iostream>

using namespace std;

int main() {
	int input;
	int count[10] = { 0 };
	int max = 0;

	cin >> input;

	while (input > 0)
	{
		count[input % 10]++;
		input /= 10;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (i != 6 && i != 9)
		{
			if (count[i] > max)
				max = count[i];
		}
	}

	count[6] += count[9] + 1;
	count[6] /= 2;

	if (count[6] > max)
		max = count[6];

	printf("%d\n", max);
}

