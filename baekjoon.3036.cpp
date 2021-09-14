/*https://www.acmicpc.net/problem/3036*/
#include <iostream>

using namespace std;
int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	int N,com =0;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	
	for (int i = 1; i < N; i++)
	{
		com = gcd(arr[0], arr[i]);
		cout << arr[0] / com << "/" << arr[i] / com << "\n";
	}

	return 0;
}
