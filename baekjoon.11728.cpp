/*https://www.acmicpc.net/problem/11728*/
#include <iostream>

using namespace std;

int arr[1000001];
int arr2[1000001];
int arr3[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> arr2[i];
	}

	int i = 0;
	int j = 0;
	int k = 0;

	while (i != N && j != M)
	{
		if (arr[i] <= arr2[j])
		{
			arr3[k] = arr[i];
			i++;
		}
		else
		{
			arr3[k] = arr2[j];
			j++;
		}
		k++;
	}
	if (i != N)
	{
		while (i != N)
		{
			arr3[k] = arr[i];
			i++;
			k++;
		}
	}
	else
	{
		while (j != M)
		{
			arr3[k] = arr2[j];
			j++;
			k++;
		}
	}

	for (int i = 0; i < k; i++)
	{
		cout << arr3[i] << " ";
	}
	return 0;
}