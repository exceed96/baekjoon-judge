/*https://www.acmicpc.net/problem/3135*/
//  그리디 문제
// A -> B 인 기준을 1씩 움직이는 A-B로 잡고 줄에 미리 지정되어 있는 주파수가 주어지면 각각의 주파수에서 B로가는데 가는 버튼수의 최솟값과 비교를 한다.

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int A, B, N;
	cin >> A >> B >> N;
	
	vector <int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] == B) // B값이 미리 지정되어 있다면 1번만 누르면 된다.
		{
			cout << 1 << "\n";
			return 0;
		}
	}

	int min = abs(A - B); // A - B를 기준으로 잡는다.
	
	for (int i = 0; i < N; i++)
	{
		if (min > abs(arr[i] - B)) // 지정되어 있는 주파수와 비교를 한다.
		{
			min = abs(arr[i] - B) + 1; // 만약 더 작으면 min에 지정되어 있는 주파수에서 B를 빼주고 1을 더한것을 min으로 대입
		}
	}

	cout << min << "\n";
	
	return 0;
}