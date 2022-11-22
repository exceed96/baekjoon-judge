#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int c = 0;
        if (N < 10)
        {
            cout << 1 << "\n";
            continue;
        }
        for(int i = 9; i >= 2; i--)
        {
            while (!(N % i))
            {
                c++;
                N /= i;
            }
            if (N == 1) break;
        }
        cout << (N == 1 ? c : -1) << "\n";
    }
}
