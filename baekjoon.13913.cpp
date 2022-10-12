#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int vis[200002];
int vis_2[200002];
int N,K;

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
            vis[next[i]] = vis[cur] + 1;
            vis_2[next[i]] = cur; //vis_2[next] 에 어느위치에서 왔는지를 넣어준다.
            Q.push(next[i]);
        }
    }
    cout << vis[K] << "\n";
    vector <int> path;
    for(int i = K; i != N; i = vis_2[i]) //동생의 위치에서 수빈이의 위치까지 행적을 따라가는 for문
        path.push_back(i); 
    path.push_back(N); // 마지막에 수빈이의 위치까지 넣어준다.
    reverse(path.begin(), path.end()); //순서가 거꾸로 되어 있으므로 reverse함수를 써서 뒤집어 준다.
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}
