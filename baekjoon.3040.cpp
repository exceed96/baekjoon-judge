/*https://www.acmicpc.net/problem/3040*/
#include <iostream>

using namespace std;

int main(void)
{
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (arr[i] + arr[j]) == 100)
			{
				sum -= arr[i] + arr[j];
				arr[i] = 0;
				arr[j] = 0;
				break;
			}
		}
		if (sum == 100)
		{
			break;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i])
		{
			cout << arr[i] << "\n";
		}
	}

	return 0;
}