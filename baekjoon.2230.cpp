#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, M, S = 2000000001;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	
	int start = 0;
	int end = 0;
	int result = 0;

	while (start < N)
	{
		int result = arr[end] - arr[start];
		if (result < M)
		{
			end++;
		}
		else
		{
			S = min(result, S);
			start++;
		}
	}

	cout << S << "\n";
	
	return 0;
}