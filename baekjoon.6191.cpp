#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char board[115][79];
int vis[115][79];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int R,C;
bool f;

vector <pair<int,int>> point;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    queue <pair<int,int>> Q;
    cin >> R >> C;
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            cin >> board[i][j];
            
    Q.push({1,1});
    vis[1][1] = 1;
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
            if (board[nx][ny] == '*' || vis[nx][ny]) continue;
            Q.push({nx,ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    
    int end = vis[R][C];
    board[R][C] = '@';
    pair <int,int> cur; cur.first = R; cur.second = C;
    point.push_back(make_pair(R,C));
    while (end)
    {
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || nx > R | ny < 1 || ny > C) continue;
            if (board[nx][ny] == '*' || vis[nx][ny] != end - 1) continue;
            point.push_back(make_pair(nx,ny));
            end--;
            cur.first = nx; cur.second = ny;
        }
        if (end == 1) break;
    }
    reverse(point.begin(), point.end());
    for(int i = 0; i < point.size(); i++)
        cout << point[i].first << " " << point[i].second << "\n";
}
