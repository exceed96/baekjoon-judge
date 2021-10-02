/*https://www.acmicpc.net/problem/2506*/
#include <iostream>

using namespace std;

int arr[100];

int main(void)
{
	int N, count = 0, result= 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i])
		{
			count++;
			result += count; //연속으로 맞을수록 count++한 값을 저장
		}
		if (!arr[i]) // 0 이 나올경우 count를 0으로 초기화
		{
			count = 0;
		}
	}
	cout << result << "\n";
	return 0;
}