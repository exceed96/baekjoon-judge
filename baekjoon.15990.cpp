/*https://www.acmicpc.net/problem/15990*/
// 2차원 배열로 풀어야 하는 dp문제
// BOJ 9095와 비슷하지만 조건이 추가로 생긴 문제이다.
// 문제에서 요구하는 바는 같은 수를 두 번 이상 연속해서 사용하면 안된다는 것이다.
// 그러기 위해서 풀이방법은 2차원 배열을 생성하여 행에는 n값을 열에는 맨 뒤의 숫자로 설정한다.
// n이 3까지의 초기값을 정해주고 4부터 반복문을 통하여서 dp를 실행한다.
// arr[n][1] 은 n을 만드는데 맨 뒤의 숫자가 1인것을 카운트 한 것이다. 그러기 위해서 i - 1번째의 수에서 끝자리가 2,3인것을 더해주면 된다.
// 이유는 예를 들어서 n을 4라고 하면 i - 1 = 3이 된다.  arr[n][1]은 즉 n값에서 마지막 숫자인 1을 뺀 3을 의미하는 것이고
// 3을 만드는 경우중에 맨 뒷자리가 2,3인것을 더해주는 것이다. 1인 경우에는 연속된 숫자가 2개이상 오기 때문에 제외한 것이다.

#include <iostream>

using namespace std;

long long arr[100001][4];
int number = 1000000009;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	arr[1][1] = arr[2][2] = arr[3][1] = arr[3][2] = arr[3][3] = 1;

	for (int i = 4; i <= 100000; i++)
	{
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % number; // n - 1값의 경우의 수중에서 맨 뒷자리가 2,3인 경우
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % number; // n - 2값의 경우의 수 중에서 맨 뒷자리가 1,3 인 경우
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % number; // n - 3값의 경우의 수 중에서 맨 뒷자리가 1,2 인 경우
	}

	while (T--)
	{
		int n;
		cin >> n;
		cout << (arr[n][1] + arr[n][2] + arr[n][3]) % number << "\n";
	}
	return 0;
}