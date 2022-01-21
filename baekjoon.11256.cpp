/*https://www.acmicpc.net/problem/11256*/
// 단순한 정렬 문제
// 각 상자의 넓이를 내림차순으로 정렬하여서 J값에다가 계속 뺴주고
// J 가 0이하일시 반복문을 종료하여서 상자 갯수를 카운트하면 된다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sort(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first * a.second > b.first * b.second;
}

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int J, N, count = 0;
		cin >> J >> N;
		vector <pair<int, int>> arr(N);
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr.begin(), arr.end(), Sort);

		for (int i = 0; i < N; i++)
		{
			J -= arr[i].first * arr[i].second;
			count++;
			if (J <= 0)
			{
				break;
			}
		}
		cout << count << "\n";
	}
	return 0;
}