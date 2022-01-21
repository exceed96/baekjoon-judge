/*https://www.acmicpc.net/problem/14247*/
// 정렬, 그리디 문제

// 하루 지날때마다 자라는 나무의 길이가 긴거를 제일 나중에 자르고 길이가 제일 짧은거를 제일 먼저 자르면 된다.
// 결국 모든 나무를 자르는게 최대값이 나온다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool Sort(const pair<int, int>& a, const pair<int, int>& b) // 자라는 길이대로 오름차순 정렬
{
	if (a.second < b.second) return 1;
	else if (a.second == b.second)
	{
		if (a.first < b.first) return 1;
	}
	return 0;
}

int main(void)
{
	int n;
	cin >> n;
	vector <pair<int, int>> arr(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), Sort);

	ll sum = arr[0].first; // sum 값이 int형의 범위를 벗어나므로 long long으로 선언
	int j = 1;

	while (1)
	{
		if (j == n) 
		{
			break;
		}
		for (int i = j; i < n; i++)
		{
			arr[i].first += arr[i].second; // 1일 지날때마다 안자른 나무들은 계속 자란다.
		}
		sum += arr[j].first; // 해당일이 되면 잘라준다.
		j++;
	}

	cout << sum << "\n";
	return 0;
}