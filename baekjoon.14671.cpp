#include <iostream>

using namespace std;

int N,M,K;
bool f[2][2];

int main(void)
{
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++)
    {
        int x,y;
        cin >> x >> y;
        f[(x + y) % 2][y % 2] = 1;        
    }
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if (!f[i][j])
            {
                cout << "NO";
                return (0);
            }
        }
    }
    cout << "YES";
    return (0);
}
