# Baekjoon.3187(양치기 꿍)

[3187번: 양치기 꿍](https://www.acmicpc.net/problem/3187)

- 이차원 bfs 알고리즘 문제

- Input
    - 입력의 첫 번째 줄에는 각각 영역의 세로와 가로의 길이를 나타내는 두 개의 정수 R, C (3 ≤ R, C ≤ 250)가 주어진다.
        
        다음 각 R줄에는 C개의 문자가 주어지며 이들은 위에서 설명한 기호들이다.
        

- Output
    - 살아남게 되는 양과 늑대의 수를 각각 순서대로 출력한다.

- Solution
    - 3184번과 풀이가 똑같다.

```cpp
#include <iostream>
#include <queue>

using namespace std;

char board[252][252];
bool vis[252][252];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int R, C, count_w, count_s;

int main(void)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'v')
                count_w++;
            if (board[i][j] == 'k')
                count_s++;
        }
    }
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            int count_v = 0, count_o = 0;
            queue <pair<int,int>> Q;
            if (vis[i][j] || board[i][j] == '#') continue;
            else
            {
                Q.push({i,j});
                vis[i][j] = 1;
                if (board[i][j] == 'v') count_v++;
                if (board[i][j] == 'k') count_o++;
                while (!Q.empty())
                {
                    pair <int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                        if (vis[nx][ny] || board[nx][ny] == '#') continue;
                        if (board[nx][ny] == 'v') count_v++;
                        if (board[nx][ny] == 'k') count_o++;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
            if (count_o > count_v) count_w -= count_v;
            else count_s -= count_o;
        }
    }
    cout << count_s << " " << count_w;
}
```
