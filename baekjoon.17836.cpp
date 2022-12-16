#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[102][102];
int vis[102][102];
int vis_2[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,M,T, s_x, s_y, s_p, result;

bool f;

int main(void)
{
    memset(vis,-1,sizeof(vis));
    memset(vis_2,-1,sizeof(vis_2));
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                s_x = i; s_y = j;
            }
        }
    }
    queue <pair<int,int>> Q;
    Q.push({1,1});
    vis[1][1] = 0;
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (board[nx][ny] == 1 || vis[nx][ny] >= 0) continue;
            if (nx == s_x && ny == s_y)
            {
                f = 1;
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                s_p = vis[cur.first][cur.second] + 1;
                break;
            }
            Q.push({nx,ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
        if (f)
            break;
    }
    while(!Q.empty())
        Q.pop();
    memset(vis, -1, sizeof(vis));
    if (f)
    {
        vis[s_x][s_y] = s_p;
        Q.push({s_x,s_y});
        while (!Q.empty())
        {
            pair <int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
                if (vis[nx][ny] >= 0) continue;
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
    }
    
    Q.push({1,1});
    vis_2[1][1] = 0;
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (vis_2[nx][ny] >= 0 || board[nx][ny]) continue;
            vis_2[nx][ny] = vis_2[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    if (vis[N][M] < 0)
        result = vis_2[N][M];
    else if (vis_2[N][M] < 0)
        result = vis[N][M];
    else
        result = min(vis[N][M], vis_2[N][M]);
    if (result <= T && 0 < result)
        cout << result;
    else
        cout << "Fail";
}
