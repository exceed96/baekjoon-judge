/*https://www.acmicpc.net/problem/11726*/
#include <iostream>
// dp문제
// 왼쪽가장자리 상단을 1 * 2로 채울시 2 * (n - 1)을 채워야하고
// 왼쪽가장자리 상단을 2 * 1로 채울시 2 * (n - 2)을 채워야한다
// 그러므로 점화식은 arr[i] = arr[i - 1] + arr[i - 2]가 나온다.
// 10007은 반복문 과정마다 해줘야 오버플로우가 발생하지 않는다.
// 초기값은 1과 2로 잡는다. 그럼 피보나치 수열과 동일한 수열이 생긴다.
using namespace std;

int arr[1001];
int number = 10007;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	arr[1] = 1;
	arr[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % number;
	}
	cout << arr[n];

	return 0;
}