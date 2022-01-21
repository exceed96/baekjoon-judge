/*https://www.acmicpc.net/problem/1920*/
#include <iostream>
#include <algorithm> //이진탐색과 정렬하기 위해서

using namespace std;

int arr[100001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
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
		cout << binary_search(arr, arr + N, t) << "\n"; //함수를 이용해서 구현
		// arr배열의 N까지의 범위에서 t값을 찾으면 1을 반환, 못찾으면 0을 반환
	}
	return 0;
}