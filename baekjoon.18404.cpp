#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int board[502][502];
int vis[502][502];

int dx[] = {-2,-2,-1,-1,1,1,2,2,};
int dy[] = {-1,1,-2,2,-2,2,-1,1};

int N,M,x,y;

queue <pair<int,int>> Q;
vector <pair<int,int>> A;

int main(void)
{
    memset(vis, -1, sizeof(vis));
    cin >> N >> M >> x >> y;
    Q.push({x,y});
    vis[x][y] = 0;
    for(int i = 0; i < M; i++)
    {
        int a_x, a_y;
        cin >> a_x >> a_y;
        A.push_back({a_x, a_y});
    }
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 8; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (vis[nx][ny] > 0) continue;
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    for(int i = 0; i < M; i++)
        cout << vis[A[i].first][A[i].second] << "\n"; 
}
