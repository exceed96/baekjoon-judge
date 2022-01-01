/*https://www.acmicpc.net/problem/4159*/
// 정렬을 사용한 그리디 문제
// 문제에서 요구하는 조건은 길 마다 충전소가 주어지고 한 번 충전하면 200마일을 이동할수 있다는 조건
// 즉 충전소간의 거리가 200마일 이상일 경우 IMPOSSIBLE, 또한 마지막 충전소에서 1422마일 까지의 거리를 가고 다시 돌아와야 하므로 
// 만약 마지막 충전소에서 델타 정션을 거치고 다시 마지막 충전소로 와서 충전해야하는데 즉 왔다갔다 왕복하는데 200마일에 못미치는 경우도 IMPOSSIBLE이다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	while (1)
	{
		bool c = true;
		int N;
		cin >> N;
		if (!N)
		{
			break;
		}

		vector <int> arr(N);

		for (int i = 0; i < N; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());

		for (int i = 1; i < N; i++)
		{
			if (arr[i] > arr[i - 1] + 200) c = false; // 충전소간의 거리가 200마일이 안될시 false
			if (arr[N - 1] + 200 < 1522) c = false; // 마지막 충전소에서 200마일을 갈 연료를 충전하고 1522마일보다 못갈시 false
		}

		if (c == true) cout << "POSSIBLE" << "\n";
		else cout << "IMPOSSIBLE" << "\n";
	}

	return 0;
}