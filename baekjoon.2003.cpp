#include <iostream>

using namespace std;

int arr[10001];

int main(void)
{
	int N, M,count = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int sum = 0;

	while (end <= N)
	{
		if (sum < M)
		{
			sum += arr[end++];
		}
		else if (sum > M)
		{
			sum -= arr[start++];
		}
		else
		{
			count++;
			sum += arr[end++];
		}
	}
	cout << count << "\n";

	return 0;
}