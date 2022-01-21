/*https://www.acmicpc.net/problem/23560*/
// dp문제
#include <iostream>

using namespace std;

int arr[16];

int main(void)
{
	int N;
	cin >> N;
	arr[1] = 2; // 초기값
	arr[2] = 6;

	for (int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2]; // 점화식
	}

	cout << arr[N] << "\n";
	return 0;
}