/*https://www.acmicpc.net/problem/11727*/
// 11726 dp문제에 2 * 2 타일이란 조건이 추가된 문제
// 11726과 동일하게 푸는 대신 2 * 2 타일에 대한 점화식을 추가해야 한다.
// 2 * n 직사각형의 가장자리 왼쪽 상단에 2 * 2를 넣으면 나머지를 넣을수 있는 것은 2 * (n - 2)가 된다.
// 그래서 arr[i - 2] * 2를 해줘야한다.

#include <iostream>

using namespace std;

int arr[1001];
int number = 10007;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + (arr[i - 2] * 2)) % number;
	}
	cout << arr[n];
	return 0;
}