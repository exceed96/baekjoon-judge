/*https://www.acmicpc.net/problem/16212*/
//단순한 정렬 문제
#include <iostream>
#include <algorithm>

using namespace std;

int arr[500001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}