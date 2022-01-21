/*https://www.acmicpc.net/problem/1246*/
#include <iostream>
#include <algorithm>
#include <vector>
// 제시한 가격을 오름차순으로 정렬하여서 가격을 하나 지정하였을때 전체 값 구해서
// 구한 전체 값 들을 비교하는 풀이
// 주의 할 점은 계란의 갯수가 손님의 인원수보다 적을수 있으므로 
// 반복문 안에 조건문을 넣어서 count가 N이 될 경우 break해야 한다.

using namespace std;

int main(void)
{
	int N, M, max = 0, index = 0;
	cin >> N >> M;
	vector <int> arr(M);
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < M; i++)
	{
		int sum = 0;
		int count = 0;

		for (int j = 0; j < M; j++)
		{
			if (arr[i] <= arr[j])
			{
				sum += arr[i];
				count++;
				if (count == N) // 이 부분을 j로 제어 할 수있으면 굳이 count를 안써도 괜찮다.
				{               // 하지만 구현에서 막혔다
					break;
				}
			}
		}
		if (max < sum)
		{
			max = sum;
			index = arr[i];
		}
	}

	cout << index << " " << max << "\n";
	return 0;
}