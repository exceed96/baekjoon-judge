/*https://www.acmicpc.net/problem/1085*/

#include <iostream>

using namespace std;

int main(void)
{
	int arr[4];
	int x, y, w, h, result1 = 0, result2 = 0;	
	cin >> x >> y >> w >> h;

	if (x < w - x) result1 = x;
	else result1 = w - x;

	if (y < h - y) result2 = y;
	else result2 = h - y;
		
	cout << min(result1, result2) << "\n";

	return 0;
}