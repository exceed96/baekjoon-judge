#include <iostream>
#include <queue> //ť ������ ���� ȣ��

using namespace std;

queue <int> arr;

int main(void)
{
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		arr.push(i); // arrť�� 1~N������ ���� ������� �־��ش�
	}

	cout << "<";
	
	while (1)
	{
		if (arr.size() == 1) //  arr�� ũ�Ⱑ 1�̸� �� ���Ҹ� ������ְ� ���ѷ��� break
		{
			cout << arr.front() << ">";
			arr.pop();
			break;
		}
		for (int i = 0; i < K - 1; i++) //EX) K = 3�̸� ���� �� ���Ҹ� �߰����ְ� �ߺ��ϴ� ���� �� ���Ҹ� �����ش�.
		{
			arr.push(arr.front());
			arr.pop();
		}
		cout << arr.front() << ", "; //K��°�� ���� ���
		arr.pop(); // ������ؼ��� �������ش�.
		// �̷��� ���ָ� ���Ҹ� �ϳ��� �ٿ��ָ鼭 �似Ǫ�����ǿ� �´� ���� ��� ����
		// BUT ũ�Ⱑ Ŀ���ٸ� �ð��� �����ɸ��°� ����
	}
	return 0;
}