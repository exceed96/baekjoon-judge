/*https://www.acmicpc.net/problem/11948*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int score1[4];
	int score2[2];
	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> score1[i];
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> score2[i];
	}

	sort(score1, score1 + 4);

	sum = score1[3] + score1[2] + score1[1] + max(score2[0], score2[1]);
	// 오름차순으로 정렬한걸 4과중에 3과목 높은걸 선택하고 2과목중에 높은 한과목을 선택

	cout << sum << "\n";
	return 0;
}