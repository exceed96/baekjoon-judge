/*https://www.acmicpc.net/problem/10816*/
#include <iostream>
#include <algorithm> 

using namespace std;

int arr[500001];
int N;

int upper(int x, int len) //찾는 원소중에 높은값을 찾아낸다
{
	int start = 0;
	int end = len;
	while (start < end) //start가 end와 같아질시 무한루프 종료 
	{
		int mid = (start + end) / 2;
		if (arr[mid] > x) //x가 mid보다 작을경우 end는 mid가 된다. 그 위에 범위에는 존재 x
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return start;
}

int lower(int x, int len) // 찾는 원소중에 낮은 값을 찾아낸다
{
	int start = 0;
	int end = len;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] >= x) 
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return start;
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
	sort(arr, arr + N);
	cin >> M;
	while (M--)
	{
		int t;
		cin >> t;
		cout << upper(t, N) - lower(t, N) << " "; //찾아낸값중에 범위가 더 큰 원소의 인덱스값과 작은 원소의 인덱스값을 빼준다.
	}

	return 0;
}