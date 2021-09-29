/*https://www.acmicpc.net/problem/2851*/
#include <iostream>

using namespace std;

int main(void)
{
	int arr[10], result = 0, m = 1000, sum = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		sum += arr[i]; 
		if (abs(100-sum) <= m) //누적하여 더한 값이 100과의 차이가 작은 값을 구하는 조건 
		{
			m = abs(100 - sum); 
			result = sum;
		}
	}
	
	cout << result << "\n";

	return 0;
}