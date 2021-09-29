/*https://www.acmicpc.net/problem/1456*/
#include <iostream>
#include <vector>

using namespace std;

int MAX = 10000000;
int arr[10000001] = {};
vector <double> arr2;

void era() // 에라토스테네스의 체
{
	for (int i = 2; i <= MAX; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i * i <= MAX; i++)
	{
		if (!arr[i])
		{
			continue;
		}
		for (int j = i * i; j <= MAX; j += i)
		{
			arr[j] = 0;
		}
	}
	for (int i = 2; i <= MAX; i++) //벡터를 추가하지 않고 하는게 베스트
	{
		if (arr[i])
		{
			arr2.push_back(i);
		}
	}
}

int main(void)
{
	long long A, B, count = 0;
	cin >> A >> B;

	for (int i = 0; i < arr2.size(); i++)
	{
		double n = arr2[i]; //제곱수를 하기 위해서 따로 변수 선언
		while (arr2[i] < B)
		{
			arr2[i] *= n; // 제곱수를 계산
			if (A <= arr2[i] && arr2[i] <= B) // 계산한값이 범위 안에 들어가면 count++
			{
				count++;
			}
		}
	}

	cout << count << "\n";
	return 0;
}