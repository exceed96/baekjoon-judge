#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		long long sum = 0;
		cin >> N;
		int* arr = new int[N];

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << "\n";
	}
	return 0;
}