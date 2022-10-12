#include <iostream>
#include <queue>

using namespace std;

int vis[200002];
int N,K,count;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> K;
    fill(vis, vis + 200002, -1);
    vis[N] = 0;
    queue <int> Q;
    Q.push(N);
    
    while (vis[K] == -1)
    {
        int cur = Q.front(); Q.pop();
        int next[3] = {cur * 2, cur - 1, cur + 1};
        for(int i = 0; i < 3; i++)
        {
            if (next[i] < 0 || next[i] > 200002) continue;
            if (vis[next[i]] != -1) continue;
            if (!i)
                vis[next[i]] = vis[cur];
            else
                vis[next[i]] = vis[cur] + 1;
            Q.push(next[i]);
        }
    }
    cout << vis[K];
}
