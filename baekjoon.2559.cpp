/*https://www.acmicpc.net/problem/2559*/
#include <iostream>

using namespace std;

int arr[100001];

int main(void)
{
	int N, K, max = -10000001, sum = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < K; i++)
	{
		sum += arr[i];
	}

	for(int i = 0; i <= N-K; i++)
	{
		if (max < sum)
		{
			max = sum;
		}
		sum -= arr[i];
		sum += arr[i + K];
	}

	cout << max << "\n";
	return 0;
}