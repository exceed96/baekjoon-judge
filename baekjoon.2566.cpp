/*https://www.acmicpc.net/problem/2566*/
#include <iostream>

using namespace std;

int main(void)
{
	int arr[9][9], max = 0 , row = 0, col = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (max < arr[i][j])
			{
				max = arr[i][j];
				row = i + 1;
				col = j + 1;
			}
		}
	}
	
	cout << max << "\n" << row << " " << col << "\n";
	
	return 0;
}