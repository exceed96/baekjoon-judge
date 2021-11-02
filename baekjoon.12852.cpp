/*https://www.acmicpc.net/problem/12852*/
// dp문제 (1463번 로직 이해 안갈시 풀이 추천)
// 정수 N에 관해서 1을 만들때 세 개의 연산을 최소로 사용하는 횟수를 출력하는 문제다.
// 1463번과 풀이는 동일하며 방법에 포함되어 있는 수는 N에서 1로 만드는 과정을 짜면된다.

#include <iostream>

using namespace std;

int arr[1000001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;

	arr[1] = 0; // N = 1일경우에는 횟수는 0번이다.

	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}
	}
	cout << arr[N] << "\n";

	while (1)
	{
		cout << N << " ";
		if (N == 1)
		{
			break;
		}
		if (arr[N] == arr[N - 1] + 1) // arr[N] 과 arr[N- 1] + 1이 같다는 경우는 1로 만드는 과정속에 1을 빼는 경우가 있다는 것이다.
		{
			N -= 1;
		}
		else if (arr[N / 2] + 1 == arr[N] && N % 2 == 0) 
		{
			N /= 2;
		}
		else if (arr[N / 3] + 1 == arr[N] && N % 3 == 0)
		{
			N /= 3;
		}
	}
	return 0;
}