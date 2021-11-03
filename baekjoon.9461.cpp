/*https://www.acmicpc.net/problem/9461*/
// 단순 dp문제
// 그림을 보고 이해할수 있는 문제이다.
// arr[i]의 값은 arr[i - 5] + arr[i - 4] + arr[i - 3]이다. 단 초기값을 인덱스 5까지는 정해줘야 한다.
#include <iostream>

using namespace std;

long long arr[101];

int main(void)
{
	int T;
	cin >> T;

	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		arr[i] = arr[i - 5] + arr[i - 4] + arr[i - 3];
	}
	while (T--)
	{
		int N;
		cin >> N;
		cout << arr[N] << "\n";
	}
	return 0;
}