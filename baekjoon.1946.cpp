/*https://www.acmicpc.net/problem/1946*/
#include <iostream>
#include <vector>
#include <algorithm>
// A의 성적이나 B 성적을 오름차순을 정렬하고 차례대로 비교하는 풀이
// 기준점이 바뀌는 경우를 생각해서 기준점을 새로 지정
using namespace std;

bool Sort(const pair<int, int> &a, const pair<int, int> &b) // 2차원 벡터의 first값을 오름차순 정렬
{
	return a.first < b.first;
}

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int count = N;
		vector <pair<int, int>> arr(N);

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i].first >> arr[i].second; 
		}

		sort(arr.begin(), arr.end(), Sort);
		
		int x = arr[0].first, y = arr[0].second;

		for (int i = 1; i < N; i++)
		{
			if (x < arr[i].first && y < arr[i].second) //x,y보다 값이 클 경우 탈락대상이므로 count에서 -1
			{
				count--;
			}
			else if (y > arr[i].second) // second에서 y값보다 작은 값이 나올경우 기준을 바꿔준다.
			{
				x = arr[i].first;
				y = arr[i].second;
			}
		}
		cout << count << "\n";
	}

	return 0;
}