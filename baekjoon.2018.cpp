#include <iostream>

using namespace std;

int main(void)
{
	int N, count = 0;

	cin >> N;

	int start = 1;
	int end = 1;
	int sum = 0;

	while (start <= N)
	{
		if (sum < N)
		{
			sum += end++;
		}
		else if (sum > N)
		{
			sum -= start++;
		}
		else if (sum == N)
		{
			sum += end++;
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}