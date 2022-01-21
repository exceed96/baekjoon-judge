/*https://www.acmicpc.net/problem/1309*/
// 2차원 배열을 이용한 dp문제
// 사자들이 울타리에 들어가는데 가로로도 세로로도 붙어 있지 않게 하는 경우의 수이다.
// 마지막에 오는 울타리 배치에 따라서 경우의 수를 따지면 된다.
// 만약 마지막에 xo 로 왔으면 뒤에 올수있는건 xx, ox가 올수 있고 xx로 왔으면 다 올수 있고, ox로 왔으면 xx, xo가 올수있다.

#include <iostream>

using namespace std;

long long arr[100001][3];
int number = 9901;

int main(void)
{
	int N;
	cin >> N;

	arr[1][0] = 1;
	arr[1][1] = 1;
	arr[1][2] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 1)
			{
				arr[i][j] += (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % number;
			}
			else if (j == 2)
			{
				arr[i][j] += (arr[i - 1][j - 1] + arr[i - 1][j - 2]) % number;
 			}
			else
			{
				arr[i][j] += (arr[i - 1][j] + arr[i - 1][j + 1] + arr[i - 1][j + 2]) % number;
			}
		}
	}

	cout << (arr[N][0] + arr[N][1] + arr[N][2]) % number << "\n";

	return 0;
}