/*https://www.acmicpc.net/problem/1978*/
#include <iostream>

using namespace std;

int number = 1000;
int arr[1001] = {};

void era()
{
	for (int i = 2; i <= number; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i * i <= number; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		for (int j = i * i; j <= number; j += i)
		{
			arr[j] = 0;
		}
	}
}

int main(void)
{
	int N,count = 0;
	cin >> N;
	int* number = new int[N];

	era();
	for (int i = 0; i < N; i++)
	{
		cin >> number[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[number[i]])
		{
			count++;
		}
	}
	
	cout << count << "\n";
	return 0;
}
