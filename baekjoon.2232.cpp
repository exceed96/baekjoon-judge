/*https://www.acmicpc.net/problem/2232*/
// 그리디 문제
// 최소 개수의 지뢰를 터트리려면 좌우의 지뢰가 자신과 같거나 더 작은 지뢰인것들만 터트리면 된다.

#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

int main(void)
{
	int N, b, count = 0;
	cin >> N;
	arr.push_back(0); // 첫번째의 i - 1번째를 비교하기 위하여 가상의 0을 넣어준다.
	for (int i = 0; i < N; i++)
	{
		cin >> b;
		arr.push_back(b);
	} 
	arr.push_back(0); // 마지막의 i + 1번째를 비교하기 위하여 가상의 0을 넣어준다.

	for (int i = 1; i < arr.size() - 1; i++)
	{
		if (arr[i - 1] <= arr[i] && arr[i + 1] <= arr[i])
		{
			cout << i << "\n"; 
		}
	}
	
	return 0;
}