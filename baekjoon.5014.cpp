#include <iostream>
#include <queue>

using namespace std;

int vis[1000002];
int F,S,G,U,D;
queue <int> Q;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> F >> S >> G >> U >> D;
    fill(vis, vis + 1000002, -1);
    vis[S] = 0;
    Q.push(S);
    
    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(int next : {cur + U, cur - D})
        {
            if (next > F || next < 1) continue;
            if (vis[next] != -1) continue;
            vis[next] = vis[cur] + 1;
            Q.push(next);
        }
    }
    if (vis[G] == -1)
        cout << "use the stairs";
    else
        cout << vis[G];
}
