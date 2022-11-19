#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

char board[52][52];
bool vis[52][52];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,M;

int main(void)
{
    int result;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];
    
    vector <tuple<int,int,int>> point;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (board[i][j] == '0' || vis[i][j]) continue;
            else
            {
                int count = 0;
                queue <pair<int,int>> Q;
                Q.push({i,j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    count++;
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny] == '0' || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                point.push_back(make_tuple(count, i, j));
            }
        }
    }
    
    memset(vis, 0, sizeof(vis));
    sort(point.begin(), point.end());
    int number = 49;
    for(int i = 0; i < point.size(); i++)
    {
        queue <pair<int,int>> Q_2;
        Q_2.push({get<1>(point[i]), get<2>(point[i])});
        vis[get<1>(point[i])][get<2>(point[i])] = 1;
        board[get<1>(point[i])][get<2>(point[i])] = number;
        while (!Q_2.empty())
        {
            pair <int,int> cur = Q_2.front(); Q_2.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (board[nx][ny] == '0' || vis[nx][ny]) continue;
                board[nx][ny] = number;
                vis[nx][ny] = 1;
                Q_2.push({nx,ny});
            }
        }
        number++;
    }
    
    for(int i = 0;  i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << board[i][j];
        cout << "\n";
    }
}
