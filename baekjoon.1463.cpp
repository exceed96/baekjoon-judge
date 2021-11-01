/*https://www.acmicpc.net/problem/1463*/
// DP문제
// N까지의 숫자들이 각각 최소한의 연산 횟수를 저장하여서 N의 최소 연산횟수를 출력한다
// 2나 3으로 나눠지면 몫이 2나 3으로 나눠지는 값이 효율적이다.
// 만약 몫이 2나 3으로 나오지 않을시 -1을 해준다.
#include <iostream>

using namespace std;

int arr[1000001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	arr[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1; 
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}
	}
	cout << arr[N];
	return 0;
}