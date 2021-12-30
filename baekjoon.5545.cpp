/*https://www.acmicpc.net/problem/5545*/
// 전형적인 그리디 문제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, A, B, D_C, result = 0, T_C = 0;

	cin >> N >> A >> B >> D_C;

	vector <int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>()); //토핑의 열량을 내림차순으로 정렬

	int max = D_C / A; //도우만 먹었을때 최대인 열량을 고려

	for (int i = 0; i < N; i++)
	{
		D_C = D_C + arr[i];
		T_C = A + (B * (i + 1));
		result = D_C / T_C; // 토핑이 들어갈시 열량계산
		if (result > max) // 열량이 최대일시 max값을 result로 
		{
			max = result;
		}
	}

	cout << max << "\n";
	return 0;
}