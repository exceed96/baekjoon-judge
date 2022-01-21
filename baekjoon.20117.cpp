/*https://www.acmicpc.net/problem/20117*/
// 정렬을 사용하는 그리디 문제
// 제일 큰 것과 제일 작은것을 묶으면 최대 이익이 나온다.
// 단 갯수가 홀수개 일때는 남은 1개를 더해줘야 한다.

#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void)
{
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	if (N % 2 == 1)
	{
		for (int i = N / 2 + 1; i < N; i++)
		{
			sum += arr[i] * 2;
		}
		sum += arr[N / 2];
	}
	else
	{
		for (int i = N / 2; i < N; i++)
		{
			sum += arr[i] * 2;
		}
	}
	cout << sum << "\n";
	return 0;
}