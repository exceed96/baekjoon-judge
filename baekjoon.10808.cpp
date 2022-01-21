/*https://www.acmicpc.net/problem/10808*/
#include <iostream>

using namespace std;

int arr[26];

int main(void)
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if ('a' <= a[i] && a[i] <= 'z')
		{
			arr[a[i] - 97]++; //아스키코드표 a(97) ~ z(122)
		}
	}
	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}