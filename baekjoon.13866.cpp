/*https://www.acmicpc.net/problem/13866*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int arr[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 4); // 오름차순으로 정렬해서 (1,4)-(2,3) 결과값이 제일 작은 차이를 가진다.

	cout << abs((arr[0] + arr[3]) - (arr[1] + arr[2])) << "\n";
	return 0;
}