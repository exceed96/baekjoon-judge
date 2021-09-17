#include <iostream>

using namespace std;

int arr[100001];

int main(void)
{

	int n, k;
	long long count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> k;

	int start = 0;
	int end = 0;
	int sum = 0;

	while (end <= n)
	{
		if (sum <= k)
		{
			sum += arr[end++];
		}
		else
		{
			sum -= arr[start++];
		}
		if (sum > k)
		{
			count += n - end + 1;
		}

	}
	cout << count << "\n";
	return 0;
}