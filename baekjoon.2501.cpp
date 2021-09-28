/*https://www.acmicpc.net/problem/2501*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, M;
	vector <int> arr;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			arr.push_back(i); //약수이면 arr벡터에 원소들을 저장
		}
	}

	if (M > arr.size()) // arr벡터의 크기보다 큰 숫자이면 0을 출력
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << arr[M - 1] << "\n";
	}
	return 0;
}