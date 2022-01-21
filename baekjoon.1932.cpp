/*https://www.acmicpc.net/problem/1932*/
// 이차원 배열을 이용한 dp문제
// 문제에서 구하고자 하는것은 각 경로마다 왼쪽 혹은 오른쪽 대각선으로 더했을 때 합이 가장 큰걸 출력하는 것이다.
// 이차원 배열을 구현하여서 arr에는 입력을 arr2에는 경로마다의 나올 수 있는 합을 넣어준다.
// 다만 무조건 합을 넣어주는 것이 아니라 그 전단계에서 최대값인 값을 가져와서 더해준다.(그래야 맨 아래 경로로 갔을때 최대인 값이 나온다.)
// 그 다음 맨 아래 줄에서 최대값을 찾아내서 출력해주면 된다.

#include <iostream>

using namespace std;

int arr[501][501];
int arr2[501][501];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, result = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	arr2[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr2[i][j] = max(arr2[i - 1][j], arr2[i - 1][j - 1]) + arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		result = max(result, arr2[n][i]);
	}

	cout << result << "\n";
	return 0;
}