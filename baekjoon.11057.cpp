/*https://www.acmicpc.net/problem/11057*/
// dp문제
// 오르막수를 구하는 문제이다.
// 이차원배열을 설정하여 i에는 자리수, j에는 마지막 수를 넣어준다.
// 자리가 1인 숫자는 무조건 오르막 수 이므로 1자리 일때는 배열에 1을 집어넣어준다.
// 자리가 2인 숫자부터는 경우의 수를 따진다.
// 오르막수란 마지막 수보다 같거나 큰 숫자를 뒤에 붙여줘야 한다.
#include <iostream>

using namespace std;

long long arr[1001][11];
int number = 10007;

int main(void)
{
	int N;
	long long count = 0;
	cin >> N;

	for (int i = 0; i <= 9; i++)
	{
		arr[1][i] = 1; // 자리가 1인 숫자는 무조건 오르막 수
	}

	for (int i = 2; i <= N; i++) 
	{
		for (int j = 0; j <= 9; j++) // 마지막 수가 0~9까지의 경우를 다 본다
		{
			for(int k = j; k <= 9; k++) // 마지막수가 만약 0 이라면 0보다 같거나 큰 숫자가 와야한다.
			{
				arr[i][j] += arr[i - 1][k] % number; // arr[2][1] 이라고 하면 그 전 자리수에서 1 과 같거나 큰 숫자가 와야한다.
			}
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		count += arr[N][i];
	}
	cout <<  count % number << "\n";
	return 0;
}