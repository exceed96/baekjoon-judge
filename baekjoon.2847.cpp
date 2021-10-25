/*https://www.acmicpc.net/problem/2847*/
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, count = 0;
	cin >> N;
	vector <int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int s = arr[N - 1]; // �������� ������ ���� �� ������ ��´�.

	for (int i = N - 2; i >= 0; i--) // ���غ��� ���ʴ�� �Ʒ��� �������鼭	                             
	{                                // ���� ���Ұ� ���� ���Һ��� Ŭ ��� 1 �� ���ָ鼭 count�� 1�� �����ش�.
		while(arr[i] >= s)
		{
			arr[i] -= 1;
			count++;
		}
		s = arr[i];
	}
	cout << count << "\n";
	return 0;
}