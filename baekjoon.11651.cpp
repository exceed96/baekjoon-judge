/*https://www.acmicpc.net/problem/11651*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Sort(const pair<int, int>& a, const pair<int, int>& b) // y좌표를 오름차순
{
	if (a.second < b.second) 
	{
		return 1;
	}
	else if (a.second == b.second) //y좌표가 동일한 경우가 있을경우 x좌표가 더 큰쪽을 앞으로 보낸다
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
	vector <pair<int, int>> arr;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y)); //벡터 2차원 입력받기
	}
	sort(arr.begin(), arr.end(), Sort); // 오름차순 정렬
	
	for (int i = 0; i < N; i++)
	{
		cout << arr[i].first << " " << arr[i].second << "\n"; //x좌표와 y좌표 출력
	}
	
	return 0;
}
