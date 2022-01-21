/*https://www.acmicpc.net/problem/9095*/
// dp문제
// 점화식을 설정하기 위해 규칙을 찾아야 한다.
// 규칙을 찾아보면 i번째의 1,2,3으로 만들수있는 연산의 수는
// arr[i - 1] + arr[i - 2] + arr[i-3] 인것을 알수있다.(표를 그려보면서 하면 규칙이 보인다.)
#include <iostream>

using namespace std;

int arr[12];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 4; i <= N; i++)
		{
			arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
		}
		cout << arr[N] << "\n";
	}
	return 0;
}