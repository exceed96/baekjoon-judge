/*https://www.acmicpc.net/problem/16435*/
#include <iostream>
#include <algorithm>
#include <vector>
//과일의 높이를 오름차순으로 정렬하여서
//스네이크 버드가 먹을 수 있는 높이면 먹고
//그러지 않을경우는 반복문을 종료( 오름차순으로 정렬한거라 더 이상 먹을수 없다.)

using namespace std;

int main(void)
{
	int N, L;
	cin >> N >> L;
	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		if (arr[i] <= L)
		{
			L++;
		}
		else
		{
			break;
		}
	}
	cout << L << "\n";
	return 0;
}