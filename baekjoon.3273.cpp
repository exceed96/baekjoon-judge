/*https://www.acmicpc.net/problem/3273*/
#include <iostream>

using namespace std;

int arr2[2000001];
int arr[100001];

int main(void)
{
	int n,x,count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (arr2[x - arr[i]] && x - arr[i] >= 0)
		{
			count++;
		}
		else
		{
			arr2[arr[i]] = 1;
		}
	}

	cout << count << "\n";
	return 0;
}
