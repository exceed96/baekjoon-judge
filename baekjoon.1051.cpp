/*https://www.acmicpc.net/problem/1051*/
#include <iostream>

using namespace std;

char arr[50][50];

int main(void)
{
	int N, M, width = 0, max = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	if (N == 1) // N이 1이면 정사각형의 최대 크기는 1
	{
		cout << "1" << "\n";
		return 0;
	}
	else
	{
		for (int i = 0; i < N-1; i++)  
		{
			for (int j = 0; j < M; j++)
			{
				for (int k = j; k < M; k++)
				{
					if (arr[i][j] == arr[i][k]) 
					{
						width = k - j + 1; // 같은 열의 원소를 찾으면 큰거에서 작은거 빼주고 +1 이 가로 길이
						if (arr[i][j] == arr[i + width - 1][j]) // 행렬로 접근할때는 width에 -1을 빼줘야한다. 이거때문에 해맸다.
						{ 
							// 정사각형이므로 가로길이 구한거에 -1 값을 열값으로 더해줘서 같은 원소임을 판별한다.
							if (arr[i + width - 1][j] == arr[i + width - 1][k])
							{
								// 같으면 width * width를 max에 저장
								if (max < width * width) //정사각형중에 최대값을 찾아준다.
								{
									max = width * width;
								}
							}
						}
					}
				}
			}
		}
	}
	
	cout << max << "\n";
	
	return 0;
}