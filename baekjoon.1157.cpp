/*https://www.acmicpc.net/problem/1157*/
#include <iostream>
#include <algorithm>

using namespace std;

int arr[26]; // 알파벳을 카운트해서 저장할 배열 A~Z

int main(void)
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int max = 0, count = 0, index = 0;
	string a;
	
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if ('a' <= a[i] && a[i] <= 'z') //문자열 a[i]가 소문자일때 카운트해줄 조건 
		{
			arr[a[i] - 97]++; //ex) a(ASCII = 97) - 97 = 0
		}
		else if ('A' <= a[i] && a[i] <= 'Z') // 문자열 a[i]가 대문자일때 카운트해줄 조건
		{
			arr[a[i] - 65]++; //ex) a(ASCII = 65) - 65 = 0
		}
	}
	max = *max_element(arr, arr + 26); //카운트중에 최대값인걸 max에 저장

	for (int i = 0; i < 26; i++)
	{
		if (max == arr[i]) //arr배열중에 max와 같으면 count++;
		{
			index = i;
			count++;
		}
	}

	if (count > 1) // count가 2이상이면 많이 사용된 알파벳이 여러개 존재
	{
		cout << "?" << "\n";
	}
	else // count가 1일경우에는 저장된 인덱스와 65를 더하여서 문자로 변환
	{
		cout << char(index + 65) << "\n";
	}
	return 0;
}
