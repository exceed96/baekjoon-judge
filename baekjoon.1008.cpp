/*https://www.acmicpc.net/problem/1008*/
#include <iostream>

using namespace std;

int main(void)
{
	int A, B;
	cin >> A >> B;
	
	cout.precision(10);
	cout << A / double(B) << "\n";
	return 0;
}