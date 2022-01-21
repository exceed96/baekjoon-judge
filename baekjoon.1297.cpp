/*https://www.acmicpc.net/problem/1297*/
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double D, H, W;
	cin >> D >> H >> W;

	double l = sqrt(D * D / (H * H + W * W)); // 주어진 비율을 피타고라스의 정리를 이용해서 정리
	cout << int(l * H) << "\n"; // 높이 길이
	cout << int(l * W) << "\n"; // 너비 길이
	return 0;
}