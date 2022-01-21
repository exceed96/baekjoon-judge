/*https://www.acmicpc.net/problem/2822*/
#include <iostream>
#include <algorithm>
// 두 개의 배열을 초기화 해서 구현
using namespace std;

int main(void)
{
	int sum = 0;
	int arr[8] = { 0 };
	int arr2[8] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
		arr2[i] = arr[i];
	}

	sort(arr, arr + 8); //오름차순으로 정렬
	for (int i = 3; i < 8; i++) 
	{
		sum += arr[i]; // 8개 문제중에 제일 높은 점수 5개를 sum에다가 더함
	}

	cout << sum << "\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 3; j < 8; j++) // 따로 저장해줬던 arr2와 arr1을 비교하여서 index를 출력
		{
			if (arr2[i] == arr[j])
			{
				cout << i+1 << " ";
			}
		}
	}
	return 0;
}