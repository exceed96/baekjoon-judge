/*https://www.acmicpc.net/problem/18258*/
// 10845문제와 동일한 풀이 다만 N의 범위가 커지면서 시간이 오래걸린다
#include <iostream>
#include <queue>

using namespace std;

queue <int> arr;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	while(N--)
	{
		string a;
		cin >> a;
		if (a == "push")
		{
			int n;
			cin >> n;
			arr.push(n);
		}
		else if (a == "pop")
		{
			if (!arr.empty())
			{
				cout << arr.front() << "\n";
				arr.pop();
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (a == "size")
		{
			cout << arr.size() << "\n";
		}
		else if (a == "empty")
		{
			cout << arr.empty() << "\n";
		}
		else if (a == "front")
		{
			if (!arr.empty())
			{
				cout << arr.front() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (a == "back")
		{
			if (!arr.empty())
			{
				cout << arr.back() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
	}
	return 0;
}