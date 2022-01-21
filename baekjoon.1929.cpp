#include <iostream>

using namespace std;

int arr[1000001] = {};
int number = 1000000;

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

	int M, N;
	cin >> N >> M;

	era();
	for (int i = N; i <= M; i++)
	{
		if (arr[i])
		{
			cout << i << "\n";
		}
	}
	return 0;
}