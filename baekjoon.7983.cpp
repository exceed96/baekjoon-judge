/*https://www.acmicpc.net/problem/7983*/
// 그리디 문제
// 전형적인 그리디 문제이다. 연속으로 최대 며칠 놀수 있는지를 요구하는 문제이다.
// 그러기 위해선 마감일을 기준으로 내림차순으로 정렬한다.
// 그리고 마감일이 제일 높은데에서 그 마감일 날짜에 걸리는 시간을 빼면 그 경우일때 쉴수있는 최대 일수가 나온다
// 원소들의 마감일을 비교하면서 만약 마감일이 놀수있는 최대 날짜보다 높으면 그 과제는 쉴수있는 날에 영향을 끼치는 것이므로
// 최대 일수에 과제에 걸리는 시간을 빼준다.
// 만약 쉴수 있는 최대 날짜보다 다음 원소의 마감일이 작다면 최대 놀수있는 날짜를 다시 설정해준다.
// 직선으로 줄을 그어놓고 날짜마다 체크하면 이해가 쉬울것이다.
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
	cin.tie(0); ios_base::sync_with_stdio(0);
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
	}

	cout << b << "\n";
	return 0;
}