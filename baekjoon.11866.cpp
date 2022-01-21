/*https://www.acmicpc.net/problem/11866*/
// 1158번 문제와 동일하게 풀이
#include <iostream>
#include <queue>

using namespace std;

queue <int> arr;

int main(void)
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		arr.push(i);
	}

	cout << "<";
	while (1)
	{
		if (arr.size() == 1)
		{
			cout << arr.front() << ">";
			arr.pop();
			break;
		}
		for (int i = 0; i < K - 1; i++)
		{
			arr.push(arr.front());
			arr.pop();
		}
		cout << arr.front() << ", ";
		arr.pop();
	}
	return 0;
}