#include <iostream>
#include <queue>

using namespace std;

char board[1002][1002];
int vis[1002][1002][2];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

queue <pair<pair<int,int>, pair<int,int>>> Q;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N,M, count = 0, result = -1;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
            
    Q.push(make_pair(make_pair(0,0), make_pair(1,0)));
    vis[0][0][0] = 1;
    
    while (!Q.empty())
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        count = Q.front().second.first;
        int d = Q.front().second.second;
        Q.pop();
        if (x == N - 1 && y == M - 1)
        {
            cout << count;
            return (0);
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '1' && !d)
            {
                Q.push(make_pair(make_pair(nx,ny), make_pair(count + 1, 1)));
                vis[nx][ny][1] = 1;
            }
            else if(board[nx][ny] == '0' && !vis[nx][ny][d])
            {
                Q.push(make_pair(make_pair(nx,ny), make_pair(count + 1, d)));
                vis[nx][ny][d] = 1;
            }
        }
    }
    cout << result;
}
