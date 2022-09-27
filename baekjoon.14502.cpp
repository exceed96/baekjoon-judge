#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[10][10];
vector <pair<int,int>> point;
queue <pair<int,int>> Q;
int N,M;
int virus, wall;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs()
{
    int count = virus;
    bool vis[10][10] = {false};
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 2)
                Q.push({i,j});
            if(board[i][j] == 1)
                vis[i][j] = 1;
        }
    }
    while (!Q.empty())
    {
        pair <int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(!vis[nx][ny] && !board[nx][ny])
            {
                Q.push({nx,ny});
                vis[nx][ny] = 1;
                count++;
            }
        }
    }
    return N * M - (count + wall + 3);
}
int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int count = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            switch (board[i][j])
            {
                case 0 : point.push_back({i,j}); break;
                case 1 : wall++; break;
                case 2 : virus++; break;
            }
        }
    
    for(int i = 0; i < point.size(); i++)
    {
        for(int j = i + 1; j < point.size(); j++)
        {
            for(int k = j + 1; k < point.size(); k++)
            {
                board[point[i].first][point[i].second] = 1;
                board[point[j].first][point[j].second] = 1;
                board[point[k].first][point[k].second] = 1;
                
                count = max(count, bfs());
                board[point[i].first][point[i].second] = 0;
                board[point[j].first][point[j].second] = 0;
                board[point[k].first][point[k].second] = 0;
            }
        }
    }
    cout << count;
}
