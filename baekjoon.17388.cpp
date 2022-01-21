/*https://www.acmicpc.net/problem/173888*/
#include <iostream>
#include <vector> //벡터를 이용해서
#include <algorithm> // 최소값을 찾아주는 함수로 접근

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
