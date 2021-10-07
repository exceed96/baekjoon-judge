#include <iostream>
#include <algorithm> //내림차순을 위해 호출

using namespace std;

int main(void)
{
	string a;
	cin >> a;
	int* arr = new int[a.length()]; //문자열의 갯수만큼 배열 동적할당

	for (int i = 0; i < a.length(); i++)
	{
		arr[i] = a[i]; //문자열의 숫자를 인트형으로 바꾼 그대로 arr배열에 저장
	}

	sort(arr, arr + a.length(), greater<>()); // greater<>()을 사용해 내림차순

	for (int i = 0; i < a.length(); i++)
	{
		cout << char(arr[i]); //인트형으로 바꾼 숫자를 다시 문자로 바꿔서 출력
	}
	return 0;
}