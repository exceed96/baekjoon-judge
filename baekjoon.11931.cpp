/*https://www.acmicpc.net/problem/11931*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>()); //greaater<int>()을 이용해 내림차순으로 정렬

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}