#include <iostream>
#include <vector> //���͸� �̿��ؼ�
#include <algorithm> // �ּҰ��� ã���ִ� �Լ��� ����

using namespace std;

int main(void)
{
	int N, sum = 0, min = 0;
	vector <int> arr;
	for (int i = 0; i < 3; i++)
	{
		cin >> N;
		arr.push_back(N);
		sum += N;
	}
	
	min = *min_element(arr.begin(), arr.end());
	if (sum >= 100)
	{
		cout << "OK" << "\n";
	}
	else
	{
		if (min == arr[0])
		{
			cout << "Soongsil" << "\n";
		}
		else if (min == arr[1])
		{
			cout << "Korea" << "\n";
		}
		else
		{
			cout << "Hanyang" << "\n";
		}
	}
	return 0;
}