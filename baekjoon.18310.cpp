/*https://www.acmicpc.net/problem/18310*/
#include <iostream>
#include <vector>
#include <algorithm>
// 중간값에 위치한 집이 결국에는 거리의 총 합이 최소가 된다.
// 정렬을 한 상태에서 집이 홀수개일 경우에는 2로 나누면 중간값이고
// 정렬을 한 상태에서 집이 짝수개일 경우에는 2가지가 나오는데 그 중에 작은 값이므로 -1을 하면 된다.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	vector <int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	if (arr.size() % 2)
	{
		cout << arr[arr.size() / 2] << "\n";
	}
	else
	{
		cout << arr[arr.size() / 2 - 1] << "\n";
	}
	return 0;
}