/*https://www.acmicpc.net/problem/1904*/
#include <iostream>
// 피보나치 수열같은 dp문제
// 위의 말 그대로 피보나치 수열같은 문제이다.
// N = 1이면 경우는 1가지, N = 2이면 경우는 2가지 N = 3이면 경우는 3가지
// 즉 arr[i] = arr[i-1] + arr[i-2] 라는 사실을 알 수 있다.
// 초기값은 1,2자리일때만 선언해놓으면 된다.

using namespace std;

long long arr[1000001];
int number = 15746;

int main(void)
{
	arr[1] = 1;
	arr[2] = 2;
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % number;
	}

	cout << arr[N];
	return 0;
}