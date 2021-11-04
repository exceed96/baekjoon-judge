/*https://www.acmicpc.net/problem/2193*/
// 간단한 dp문제
// 0으로 시작하지 않고 1이 연속으로 두번 즉 11을 부분 문자열로 가지고 있지 않은 이친수를 찾는것이다.
// 정리해 보자면 0 뒤에는 0,1이 둘다 올수있고, 1 뒤에는 무조건 0이 와야 하는 것이다.
// 초기값과 점화식을 위의 두 조건으로 잡아주고 N자리에서 맨뒤가 1,0인 이친수들의 경우의 수를 더해주면 된다.
#include <iostream>

using namespace std;

long long arr[90][2];

int main(void)
{
	int N;
	cin >> N;
	
	arr[1][1] = 1;
	arr[2][0] = 1;

	for (int i = 3; i <= N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				arr[i][j] = arr[i - 1][0] + arr[i - 1][1];
			}
			else
			{
				arr[i][j] = arr[i - 1][0];
			}
		}
	}

	cout << arr[N][1] + arr[N][0] << "\n";
	return 0;
}