#include <iostream>

using namespace std;

int main(void)
{
	int N, min = 1001, max = 0;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (min > arr[i])
		{
			min = arr[i];
		}
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	cout << max - min << "\n";


	return 0;
}