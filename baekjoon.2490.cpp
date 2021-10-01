/*https://www.acmicpc.net/problem/2490*/
#include <iostream>

using namespace std;

int main(void)
{
	int i = 3;
	while (i--)
	{
		int arr[4], count = 0;
		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			if (arr[i])
			{
				count++; 
			}
		}
		//1이 나온 갯수만큼 구분지어서 출력
		if (!count)
		{
			cout << "D" << "\n";
		}
		else if (count == 4)
		{
			cout << "E" << "\n";
		}
		else if (count == 3)
		{
			cout << "A" << "\n";
		}
		else if (count == 2)
		{
			cout << "B" << "\n";
		}
		else
		{
			cout << "C" << "\n";
		}
	}
	return 0;
}