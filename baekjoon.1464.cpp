/*https://www.acmicpc.net/problem/1464*/
// 그리디 + 정렬 + 문자열 문제
// 문제에서 요구하는 것은 문제에서 명시된 뒤집기 방법으로 만들 수 있는 문자열 중 사전순으로 제일 앞서는 것을 출력
// 여기서 생각해볼수 있는 풀이는 사전순으로 가장 앞서는 문자를 맨뒤로 보내고 출력전에 reverse해주면 사전순으로 제일 앞서는 문자열이 나온다.
// 그러기 위해서는 맨 앞의 문자부터 한칸 뒤의 원소와 비교해서 뒤의 원소가 사전순으로 뒤에 있으면 역순을 해주고 역순을 해준 칸보다 한칸뒤의 문자열 까지 reverse를 해줘야한다.
// 그래야 사전순으로 제일 앞에있는 문자를 뒤로 계속 밀어버릴수 있다.

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	string a;
	cin >> a;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[i - 1] < a[i])
		{
			reverse(a.begin(), a.begin() + i);
			reverse(a.begin(), a.begin() + i + 1);
		}
	}
	reverse(a.begin(), a.end());

	cout << a << "\n";
	return 0;
}