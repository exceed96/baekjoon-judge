/*https://www.acmicpc.net/problem/15565*/
#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int N, K, a, max = 1000001;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 1)
		{
			arr.push_back(i);
		}
	}

	if (arr.size() < K)
	{
		cout << "-1" << "\n";
		return 0;
	}
	
	for (int i = 0; i <= arr.size() - K; i++)
	{
		max = min(max, arr[i + K - 1] - arr[i] + 1);
	}
	cout << max << "\n";
	return 0;
}