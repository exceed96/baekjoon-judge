/*https://www.acmicpc.net/problem/13164*/
// �׸��� ����
// Ƽ���� ����� ��� �ּҷ� �Ͽ��� ����ؾ��Ѵ�.
// �ּҷ� �ϱ� ���ؼ��� �������� ������������ ���� �Ͽ��� �ؾ� ������ �������� �־��� ���ǿ� �������� �̹� Ű ������� �� �������ִ�.
// �������� Ű ���̸� arr2���Ϳ� �����ϰ� ������������ ������ �� N-K��ŭ�� ���� ���Ұ��� �����ָ�
// �ּ�  Ƽ���� ����� ���´�.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K, sum = 0;
	cin >> N >> K;
	vector <int> arr(N);
	vector <int> arr2;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (i >= 1)
		{
			arr2.push_back(arr[i] - arr[i - 1]);
		}
	}
	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < N - K; i++)
	{
		sum += arr2[i];
	}
	cout << sum << "\n";
	
	
	return 0;
}