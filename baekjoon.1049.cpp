#include <iostream>

using namespace std;

int main(void)
{
	int N, M, min = 1001, min2 = 1001, result = 0;
	cin >> N >> M;
	int* arr = new int[M];
	int* arr2 = new int[M];

	for (int i = 0; i < M; i++)
	{
		cin >> arr[i] >> arr2[i];
		if (min > arr[i])
		{
			min = arr[i];
		}
		if (min2 > arr2[i])
		{
			min2 = arr2[i];
		}
	}
	
	if (min / 6 >= min2)
	{
		result = min2 * N;
	}
	else
	{
		if ((N / 6 + 1) * min < (N / 6 * min) + (N % 6 * min2))
		{
			result = (N / 6 + 1) * min;
		}
		else
		{
			result = (N / 6 * min) + (N % 6 * min2);
		}
	}

	cout << result << "\n";
	return 0;
}