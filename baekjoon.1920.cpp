/*https://www.acmicpc.net/problem/1920*/
#include <iostream>
#include <algorithm> //정렬stl을 쓰기위해서 

using namespace std;

int arr[100001];
int N;

int binary(int x) //이진탐색을 위한 함수
{
	int start = 0;
	int end = N - 1;
	while (start <= end) //start 가 end를 넘어가면 해당하는 숫자가 없는것이므로 무한루프 종료, 0을 반환
	{
		int mid = (start + end) / 2; // 중간값을 지정
		if (arr[mid] > x) //중간값보다 x가 작다면 중간값보다 작은 범위를 탐색
		{
			end = mid - 1; // end값을 mid - 1로 지정
		}
		else if (arr[mid] < x) // 중간값보다 x가 크다면 중간값보다 큰 범위를 탐색
		{
			start = mid + 1; // start값을 mid+1로 지정
		}
		else
		{
			return 1; // 값을 찾으면 1을 반환(arr[mid] == x)
		}
	}
	return 0;
}

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N); //이진탐색을 위해서 정렬을 해준다.
	cin >> M;
	while (M--)
	{
		int t;
		cin >> t;
		cout << binary(t) << "\n";
	}
	return 0;
}