/*https://www.acmicpc.net/problem/1124*/
#include <iostream>
#include <vector>

using namespace std;

int number = 100000;
int arr[100001];
vector <int> arr2;

void era() // 에라토스테네스의 체 알고리즘
{
	for (int i = 2; i <= number; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i * i <= number; i++)
	{
		if (!arr[i])
		{
			continue;
		}
		for (int j = i * i; j <= number; j += i)
		{
			arr[j] = 0;
		}
	}
	for (int i = 2; i <= number; i++) //에라토스테네스의 체 알고리즘을 통해 나온 소수들을 0번째부터 arr2벡터에 저장
	{
		if (arr[i])
		{
			arr2.push_back(i);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int A,B,count = 0, count2 = 0;
	cin >> A >> B;
	era();

	for (int i = A; i <= B; i++)
	{
		int count = 0;
		int n = i;
		for (int j = 0; j <= arr2.size(); j++) //arr2배열에 있는 소수값 원소
		{
			while(n % arr2[j] == 0) // 나머지가 0일시 나누기 한 값에서 한번더 하고 0이 아닐시에는 j가 1씩 증가
			{
				count++;
				n /= arr2[j];
			
			}
			if (n == 1) // 맨 마지막에는 결국 1만 남게 되면서 break
			{
				break;
			}
		}
		if (arr[count]) // 약수의 갯수가 소수의 수 이면 arr배열에서 비교하여서 count2++
		{
			count2++;
		}
	}

	cout << count2 << "\n";
	return 0;
}