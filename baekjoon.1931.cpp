/*https://www.acmicpc.net/problem/1931*/
// 회의가 끝나는 시간을 오름차순으로 정렬하고 끝나는 시간에 맞춰서
// 시작하는시간이 제일 빠른 회의를 찾아주면 회의의 최대갯수를 알 수 있다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort(const pair<int, int> &a, const pair<int, int> &b)
// 회의가 끝나는 시간을 오름차순으로 정렬
{
	if (a.second < b.second)
	{
		return 1;
	}
	else if (a.second == b.second) //끝나는 시간이 같을경우 시작하는시간을 비교하여서 오름차순 정렬
	{
		if (a.first < b.first)
		{
			return 1;
		}
	}
	return 0;
}
int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, s = 0, count = 0;
	cin >> N;
	vector <pair<int, int>> arr(N); // 2차원벡터 N개 

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), Sort); // 끝나는 시간을 오름차순으로 정렬

	for (int i = 0; i < N; i++)
	{
		if (s <= arr[i].first) // 시작하는 시간이 s랑 같거나 크다면 
		{
			s = arr[i].second; //끝나는 시간을 s에 저장
			count++; 
		}
	}
	cout << count << "\n";
	return 0;
}