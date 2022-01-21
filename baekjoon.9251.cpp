/*https://www.acmicpc.net/problem/9251*/
// 이차원 배열을 이용한 dp문제
// 이차원 배열을 이용해야 하는 문제이다. 표를 그리면서 확인해보면 규칙이 보인다.
// 만약 a의 문자열 첫번째 원소와 b 전체를 비교해본다. 
// 만약 같으면 왼쪽 대각선 위에 있는 값에서 + 1을 해주고 만약 다르면  i - 1 혹은 j - 1 값중에 큰 값을 가져온다.

#include <iostream>

using namespace std;

int arr[1001][1001];

int main(void)
{
	string a, b;

	cin >> a >> b;

	int size_a = a.size();
	int size_b = b.size();

	for (int i = 1; i <= size_a; i++)
	{
		for (int j = 1; j <= size_b; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	cout << arr[size_a][size_b] << "\n";
	return 0;
}