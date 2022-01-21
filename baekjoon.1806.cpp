#include <iostream>

using namespace std;

int arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int min = S + 1;
	int start = 0;
	int end = 0;
	int sum = 0;
	int result = 0;

	while (end <= N)
	{
		if (sum < S)
		{
			sum += arr[end++];
		}
		else if (sum >= S)
		{
			result = end - start;
			if (result < min)
			{
				min = result;
			}
			sum -= arr[start++];
		}
	}
	if (!result)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << min << "\n";
	}
	return 0;
}