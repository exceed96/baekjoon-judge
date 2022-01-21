/*https://www.acmicpc.net/problem/14495*/
// 피보나치 수열을 변형한 dp문제
// 문제에 점화식과 초기값이 다 나와 있다.

#include <iostream>

using namespace std;

long long arr[117];

int main(void)
{
	arr[1] = arr[2] = arr[3] = 1;
	int n;
	cin >> n;
	for (int i = 4; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 3];
	}
	cout << arr[n];
	return 0;
}