/*https://www.acmicpc.net/problem/10844*/
// 이차원 배열을 dp문제
// 인접한 모든자리의 차이가 1인 계단수를 구해야 하는 문제이다.
// 규칙을 찾아보면 끝자리가 0과 9일 때를 예외로 생각해서 풀 수있다.
// 마지막자리수가 0 이라면 앞에 올수있는 수는 1, 마지막 자리수가 9라면 앞에 올수 있는 수는 8 이렇게
// 각각 1개씩만 존재하게 된다.
// 2 ~ 8 까지는 -1 , + 1한 값이 존재할수있다 예를 들면 x2라고 하면 x에는 1 or 3이 올수있다.

#include <iostream>

using namespace std;

long long arr[101][11];
int number = 1000000000;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	long long N, count = 0;
	cin >> N;
	arr[1][0] = 0;

	for (int i = 1; i <= 10; i++)
	{
		arr[1][i] = 1;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				arr[i][j] = arr[i - 1][j + 1] % number;
			}
			else if (j == 9)
			{
				arr[i][j] = arr[i - 1][j - 1] % number;
			}
			else
			{
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % number;
			}
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		count += arr[N][i];
	}
	cout << count % number << "\n";
	return 0;
}