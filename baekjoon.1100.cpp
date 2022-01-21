#include <iostream>

using namespace std;

int main(void)
{
	int count = 0;
	char arr[8][8]; // 2차원 배열 선언

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0; i < 8; i++)
	{
		if (i % 2) // i가 홀수이면 WBWBWBWB
		{
			for (int j = 1; j < 8; j += 2)
			{
				if (arr[i][j] == 'F')
				{
					count++;
				}
			}
		}
		else //i가 짝수이면 BWBWBWBW
		{
			for (int j = 0; j < 8; j += 2)
			{
				if (arr[i][j] == 'F')
				{
					count++;
				}
			}
		}
	}

	cout << count << "\n";
	return 0;
}