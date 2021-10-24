/*https://www.acmicpc.net/problem/1449*/
#include <iostream>
#include <vector>
#include <algorithm>
// 입력받을 벡터 1개와 테이프가 붙여지는 곳의 확인 유무를 저장할 행렬 하나를 설정하여서 풀이
using namespace std;

int arr2[1001];

int main(void)
{
	int N, L, count = 0;
	cin >> N >> L;
	vector <int> arr(N); 
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for(int i = 0; i < N; i++)
	{
		if (!arr2[arr[i]]) // arr2의 행렬이 1일경우 테이프가 붙여진 곳이다. 
		{
			for (int j = arr[i]; j < min(arr[i] + L, 1001); j++)
			// arr[i]부터 arr[i] + L까지의 거리만큼 테이프가 붙여지므로 그 지점은 1로 초기화한다.
			// 반복문을 실행할경우 붙여진 곳은 위의 조건문을 통해서 PASS 하고 안붙여진 지점만 찾아낸다
			{
				arr2[j] = 1;
			}
			count++; // 붙여지면 COUNT++
		}
	}
	cout << count << "\n";
	return 0;
}