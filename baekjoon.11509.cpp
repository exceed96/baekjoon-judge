/*https://www.acmicpc.net/problem/11509*/
// 인덱스로 접근해야 하는 그리디 문제
// 화살이 왼쪽에서 오른쪽으로 날아가는데 인덱스를 높이라고 생각하여 풀이
// 화살이 날아와서 풍선이 터질시 화살은 그 전에 원래의 자리보다 1 높은 자리에 위치하고 있다.
// 그럼 그 전에 인덱스의 값이 1일시에는 화살이 날라와서 풍선을 터트리는 것이다.
// 만약 그 전에 자리가 0 일시에는 화살이 날라오지 않는것이므로 그 자리를 +1 해주고 화살의 갯수를 +1 해주면 된다.

#include <iostream>

using namespace std;

int arr[1000001];

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		if (arr[a + 1])
		{
			arr[a]++;
			arr[a + 1]--;
		}
		else
		{
			arr[a]++;
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}