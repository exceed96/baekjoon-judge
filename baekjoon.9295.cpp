/*https://www.acmicpc.net/problem/9295*/
#include <iostream>

using namespace std;

int main(void)
{
	int T,index = 1;
	cin >> T;
	while (T--)
	{
		int A, B;
		cin >> A >> B;
		cout << "Case " << index << ": " << A + B << "\n";
		index++;
	}
	return 0;
}