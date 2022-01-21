#include <iostream>
#include <vector>

using namespace std;

int number = 4000000;
int arr[4000001];
vector <int> arr2;

void era()
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
	for (int i = 2; i <= number; i++)
	{
		if (arr[i])
		{
			arr2.push_back(i);
		}
	}
}

int main(void)
{
	era();
	int N,sum = 0,count = 0;
	cin >> N;

	int start = 0;
	int end = 0;

	while (1)
	{
		if (sum < N)
		{
			sum += arr2[end++];
		}
		else if (end == arr2.size())
		{
			break;
		}
		else
		{
			sum -= arr2[start++];
		}
		if (sum == N)
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}