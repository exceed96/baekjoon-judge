/*https://www.acmicpc.net/problem/2902*/

using namespace std;

int main(void)
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if ('A' <= a[i] && a[i] <= 'Z') //문자열의 원소가 대문자이면 원소 출력
		{
			cout << a[i];
		}
	}
	return 0;
}