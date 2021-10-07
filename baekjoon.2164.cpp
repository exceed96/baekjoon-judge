/*https://www.acmicpc.net/problem/2164*/
#include <iostream>
#include <queue>

using namespace std;

queue <int> arr;

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		arr.push(i); // 1~N까지의 숫자를 arr큐에 저장
	}

	while (arr.size() != 1) //큐의 크기가 1일때까지 반복
	{
		arr.pop(); // 맨 앞 숫자를 지워준다 ex) N = 4  -> 2,3,4
		arr.push(arr.front()); // 지워진 수의 다음숫자를 맨뒤에 추가 2,3,4,2
		arr.pop(); // 맨 앞 숫자를 지워준다 3,4,2
	}
	cout << arr.front() << "\n";
 	return 0;
}