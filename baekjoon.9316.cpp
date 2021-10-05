/*https://www.acmicpc.net/problem/9316*/
#include <iostream>

using namespace std;

int main(void)
{
	int N, i = 1;
	cin >> N;

	while (i)
	{
		cout << "Hello World, Judge" << " " << i << "!" << "\n";
		if (i == N)
		{
			break;
		}
		i++;
	}
	return 0;
}