#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int arr[10];
bool isused[10]; //특정 수가 쓰였는지를 true 혹은 false로 나타내는 배열

void func(int num, int k)
{
    if (k == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return ;
    }
    for(int i = num; i <= n; i++)
    {
        if(!isused[i])
        {
            arr[k] = i;
            isused[i] = 1;
            func(i + 1, k + 1);
            isused[i] = 0;
        }
    }
}
int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    func(1, 0);
}
