/*https://www.acmicpc.net/problem/10610*/
// 문자열 정렬 문제
// string으로 문자열을 받은후 내림차순 정렬 후 문자열 마지막에 0이 없을시에는 30의 배수가 아니므로 -1 출력 후 종료
// 0이 있을시에는 문자열 원소 하나하나를 더해줘서 3으로 나눠서 나머지가 0일시 30의 배수이므로
// a를 출력해준다.
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	long long sum = 0;
	string a;
	cin >> a;
	sort(a.begin(), a.end(), greater<>());

	if (a[a.size() - 1] != '0')
	{
		cout << -1 << "\n";
		return 0;
	}
	else
	{
		for (int i = 0; i < a.size() - 1; i++)
		{
			sum += int(a[i]);
		}
		if (sum % 3 == 0)
		{
			cout << a << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
	}
	return 0;
}