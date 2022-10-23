#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int board[102][102];
bool vis[102][102];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int N,M,K;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M >> K;
    int count = 0;
    while (K--)
    {
        int Y,Y_2,X,X_2;
        cin >> X >> Y >> X_2 >> Y_2;
        for(int i = Y; i < Y_2; i++)
            for(int j = X; j < X_2; j++)
                board[i][j] = 1;
    }
    
    vector <int> v;
    queue <pair<int,int>> Q;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int count2 = 1;
            if (vis[i][j] == 1 || board[i][j] == 1) continue;
            else
            {
                count++;
                Q.push({i,j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M || (vis[nx][ny] || board[nx][ny])) continue;
                        count2++;
                        Q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            v.push_back(count2);
        }
    }
    cout << count << "\n";
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
