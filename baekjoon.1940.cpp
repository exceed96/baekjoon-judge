#include <iostream>
#include <algorithm>

using namespace std;

int arr[15001];

int main(void)
{
	int N, M, count = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int start = 0;
	int end = N - 1;
	int sum = 0;

	while (start < end)
	{
		sum = arr[start] + arr[end];
		if (sum < M)
		{
			start++;
		}
		else if (sum > M)
		{
			end--;
		}
		else
		{
			count++;
			end--;
			start++;
		}
	}

	cout << count << "\n";
	return 0;
}