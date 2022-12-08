#include <iostream>
#include <queue>

using namespace std;

int vis[2000002];
queue <int> Q;

int A,K;

int main(void)
{
    cin >> A >> K;
    fill(vis, vis + 2000002, -1);
    vis[A] = 0;
    Q.push(A);
    
    while (vis[K] == -1)
    {
        int cur = Q.front(); Q.pop();
        for(int next: {cur + 1, cur * 2})
        {
            if (next < 0 || next > 2000002) continue;
            if (vis[next] != -1) continue;
            if (next == K)
            {
                cout << vis[cur] + 1;
                return (0);
            }
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
    }
}
