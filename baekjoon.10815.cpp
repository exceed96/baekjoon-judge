/*https://www.acmicpc.net/problem/10815*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[500001];
int N;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	while (M--)
	{
		int t;
		cin >> t;
		cout << binary_search(arr, arr + N, t) << " ";
	}
	
	return 0;
}