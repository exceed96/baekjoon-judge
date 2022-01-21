/*https://www.acmicpc.net/problem/10816*/
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
		cout << upper_bound(arr, arr + N, t) - lower_bound(arr, arr + N, t) << " ";
		// upper_bound와 lower_bound를 이용해서 갯수를 구해준다. 
	}
	return 0;
}