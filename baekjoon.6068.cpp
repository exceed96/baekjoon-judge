/*https://www.acmicpc.net/problem/6068*/
// 7983과 동일한 논리의 그리디 문제
// 7983번과 똑같은 문제이다 다만 추가된 조건은 제 시간에 일을 끝낼수 없다면 -1일 출력하는 것이다.
// 제 시간에 일을 끝낼수 없다는 말은 즉 일어나는 시간이 0 미만일때를 말하는 것이다.
// 위의 조건만 추가해주면 된다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second;
}

int main(void)
{
	int n;
	cin >> n;
	vector <pair<int, int>> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), Sort);

	int b = arr[0].second - arr[0].first;

	for (int i = 1; i < n; i++)
	{
		if (arr[i].second > b)
		{
			b -= arr[i].first;
		}
		else
		{
			b = arr[i].second - arr[i].first;
		}
		if (b < 0)
		{
			cout << -1;
			return 0;
		}
	}

	cout << b << "\n";
	return 0;
}