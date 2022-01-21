/*https://www.acmicpc.net/problem/5612*/
#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n, m, max = 0;
	cin >> n >> m; // 시간과 초기 차량의 수 입력
	max = m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		m = m + a - b;
		if (m < 0) // 터널안의 차량이 음수가 된다면 0을 출력하고 종료
		{
			cout << "0" << "\n";
			return 0;
		}
		if (max < m) // 터널안의 차량이 max값보다 클경우 max에 m 저장
		{
			max = m;
		}
	}
	cout << max << "\n"; // 가장 많을때인 max를 출력
	return 0;
}