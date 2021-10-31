/*https://www.acmicpc.net/problem/1092*/
// 정렬 + 그리디 문제
// 무게 제한이 큰 크레인 순으로 무거운 상자들을 옮기는 풀이
// 위의 풀이를 하기 위해선 크레인의 무게제한값과 상자의 값들을 내림차순 or 오름차순 해야한다.
// 그 다음 무게 제한이 가장 큰 크레인 순서대로 무거운 상자들을 순서대로 옮긴다.
// 이미 옮긴 상자는 배열 값을 0으로 만들어서 다음 루프를 돌때에는 패스하도록 한다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N;
	vector <int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	
	cin >> M;
	vector <int> arr2(M);
	for (int i = 0; i < M; i++)
	{
		cin >> arr2[i];
	}
	sort(arr2.begin(), arr2.end(), greater<int>());

	if (arr[0] < arr2[0]) //내림차순 정렬시 각 벡터의 맨 앞 원소값이 상자의 무게가 크면 다 못옮기므로 -1 출력
	{
		cout << -1 << "\n";
		return 0;
	}
	else
	{
		int b = 0, time = 0;
		while (b != M)
		{
			time++;
			int N_ = 0;
			for (int i = 0; i < M; i++)
			{
				if (!arr2[i]) //벡터값이 0일시 패스
				{
					continue;
				}
				if (N_ == N) // N_값이 N이 된다면 N_은 다시 0부터 시작해야하므로 break;
				{
					break;
				}
				if (arr[N_] >= arr2[i])
				{
					b++; //b는 즉 박스의 갯수, b가 M이 된다면 다 옮긴것이므로 무한루프가 종료된다.
					N_++;
					arr2[i] = 0;
				}
			}
		}
		cout << time << "\n";
	}

	return 0;
}