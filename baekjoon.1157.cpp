/*https://www.acmicpc.net/problem/1157*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[26]; // ���ĺ��� ī��Ʈ�ؼ� ������ �迭 A~Z

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int max = 0, count = 0, index = 0;
	string a;
	
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if ('a' <= a[i] && a[i] <= 'z') //���ڿ� a[i]�� �ҹ����϶� ī��Ʈ���� ���� 
		{
			arr[a[i] - 97]++; //ex) a(ASCII = 97) - 97 = 0
		}
		else if ('A' <= a[i] && a[i] <= 'Z') // ���ڿ� a[i]�� �빮���϶� ī��Ʈ���� ����
		{
			arr[a[i] - 65]++; //ex) a(ASCLL = 65) - 65 = 0
		}
	}
	max = *max_element(arr, arr + 26); //ī��Ʈ�߿� �ִ밪�ΰ� max�� ����

	for (int i = 0; i < 26; i++)
	{
		if (max == arr[i]) //arr�迭�߿� max�� ������ count++;
		{
			index = i;
			count++;
		}
	}

	if (count > 1) // count�� 2�̻��̸� ���� ���� ���ĺ��� ������ ����
	{
		cout << "?" << "\n";
	}
	else // count�� 1�ϰ�쿡�� ����� �ε����� 65�� ���Ͽ��� ���ڷ� ��ȯ
	{
		cout << char(index + 65) << "\n";
	}
	return 0;
}