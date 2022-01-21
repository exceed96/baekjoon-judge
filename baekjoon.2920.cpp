/*https://www.acmicpc.net/problem/2920*/
#include <iostream>

using namespace std;

int main(void)
{
	int arr[8] = {}, count = 0, count2 = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		if (arr[i] + arr[7-i] == 9) // 맨앞과 맨뒤의 합이 9이고
		{
			if (arr[i] < arr[i + 1]) // 뒤의 원소가 앞의 원소보다 크다면 count++ 즉 오름차순
				count++;
			else
				count2++; // 뒤의 원소가 앞의 원소보다 작다면 count2++ 즉 내림차순
		}
	}
	if (count == 4 && arr[0] == 1) // 오름차순일때
	{
		cout << "ascending" << "\n";
	} 
	else if (count2 == 4 && arr[0] == 8) // 내림차순일때
	{
		cout << "descending" << "\n";
	}
	else // 그 외에는 mixed
	{
		cout << "mixed" << "\n";
	}
	return 0;
}