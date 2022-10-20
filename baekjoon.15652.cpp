#include <iostream>

using namespace std;

int n,m;
int arr[10];
//bool isused[10];

void func(int k)
{
    if (k == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        //if (!isused[i])
        //{
            arr[k] = i;
            //isused[i] = 1;
            if (k >= 1 && arr[k - 1] > arr[k])  continue;
            func(k + 1);
            //isused[i] = 0;
        //}
    }
}

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    func(0);
}
