/*https://www.acmicpc.net/problem/14650*/
// 간단한 DP문제
// 처음에는 각자리수를 더한 값을 3으로 더해서 나머지값을 기준삼아서 이차원배열을 생성하여 풀려고 했지만 안풀렸다.
// 그래서 규칙을 찾아보니 arr[i]는 arr[i - 1] * 3이란 규칙을 찾아냈다.
// 초기값은 arr[2] = 2로 잡고 점화식은 arr[i - 1] * 3으로 잡으면 된다.

#include <iostream>

using namespace std;

int arr[9];

int main(void)
{
	int N;
	cin >> N;
	
	arr[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		arr[i] = arr[i - 1] * 3;
	}
	cout << arr[N];
	return 0;
}