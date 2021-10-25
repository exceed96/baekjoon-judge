/*https://www.acmicpc.net/problem/9237*/
#include <iostream>
#include <vector>
#include <algorithm>
// ������ �� �ڶ�µ� �ɸ��� �ϼ��� ������������ �����Ͽ��� ������ ���ҿ� ���Ҹ��� �ش��ϴ�
// �ε��� ���� �����ְ� 1�� �����ָ� ������ �� �ڶ�µ� �ɸ��� �ð��� ��������.
// �ð��� ���ϰ� �ű�� 1�� �����ָ� ������� �ʴ��ϴµ� �ɸ��� ��¥�� ��������.
// ������� ������ �� �ڶ�� �������� ���� ���̹Ƿ� 1�� �����ִ� ���̴�.
using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, max_day = 0;
	cin >> N;
	vector <int> arr(N); 

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>()); // ��������

	for (int i = 0; i < N; i++)
	{
		max_day = max(max_day, i + arr[i] + 1); // ����ؼ� �����ָ鼭 �ִ밪�� max_day�� ����
	}

	cout << max_day + 1 << "\n"; // ������ �������� �� �ڶ�� �������� ���Ƿ� +1�� ���ش�.
	return 0;
}