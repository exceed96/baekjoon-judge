/*https://www.acmicpc.net/problem/11650*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Sort(const pair<int, int>& a, const pair<int, int>& b) 
{
	if (a.first < b.first) //x좌표끼리 크기를 비교하여서 작은거를 앞에다 보낸다
	{
		return 1;
	}
	else if (a.first == b.first) // x좌표가 같을경우 y좌표끼리 비교
	{
		if (a.second < b.second)
		{
			return 1;
		}
	}
	return 0;
}
int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	vector <pair<int, int>> arr;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
	}
	sort(arr.begin(), arr.end(), Sort);
	
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
	
	return 0;
}
