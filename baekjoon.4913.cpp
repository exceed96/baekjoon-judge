/*https://www.acmicpc.net/problem/4913*/
#include <iostream>
#include <vector>

using namespace std;

int number = 1000000;
bool arr[1000001] = { false, };
vector <int> arr2;

void era() //에라토스테네스의 체
{
	for (int i = 2; i * i <= number; i++)
	{
		if (!arr[i])
		{
			for (int j = i * i; j <= number; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i <= number; i++)
	{
		if (!arr[i])
		{
			arr2.push_back(i);
		}
	}
}

int main(void)
{
	era();
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (1)
	{
		int L, U, count = 0, count2 = 0;
		
		
		cin >> L >> U;
		
		if (L == -1 && U == -1) // L과 U가 -1일때 무한루프 종료
		{
			break;
		}

		for (int i = 0; i < arr2.size(); i++)
		{
			if (L <= arr2[i] && arr2[i] <= U) // 범위안에 소수가 있으면 count++
			{
				count++;
				if (arr2[i] % 4 == 1 || arr2[i] == 2) // 소수가 4로 나눠서 나머지가 1일시 제곱수의 합으로 나타낼수 있다.
				{                                     // 다만 2일시에는 1의 제곱 두개의 합으로 나타낼수있어서 따로 조건을 설정
					count2++;
				}
			}
			if (arr2[i] > U) // 소수배열이 U를 넘어갈시 반복문 종료
			{
				break;
			}
		}

		cout << L << " " << U << " " << count << " " << count2 << "\n";
	}
	return 0;
}