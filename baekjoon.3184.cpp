# Baekjoon.3184(양)

[3184번: 양](https://www.acmicpc.net/problem/3184)

- bfs알고리즘 문제

- Input
    - 첫 줄에는 두 정수 R과 C가 주어지며(3 ≤ R, C ≤ 250), 각 수는 마당의 행과 열의 수를 의미한다.
        
        다음 R개의 줄은 C개의 글자를 가진다. 이들은 마당의 구조(울타리, 양, 늑대의 위치)를 의미한다.
        

- Output
    - 하나의 줄에 아침까지 살아있는 양과 늑대의 수를 의미하는 두 정수를 출력한다.

- Solution
    - 이차원 bfs알고리즘을 이용해서 문제를 풀면 쉽게 푼다.
    - 단지 추가된 조건으로 양의 수가 늑대의 수보다 많을때는 늑대의 전체 카운트에서 빼주고 늑대의 수가 양의수와 같거나 클 경우에는 양의 전체 카운트에서 빼주면 된다.

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
            if (board[i][j] == 'o')
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
                if (board[i][j] == 'v') count_v++; //현재 자리에서도 양인지 늑대인지를 판단
                if (board[i][j] == 'o') count_o++;
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
                        if (board[nx][ny] == 'o') count_o++;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
            if (count_o > count_v) count_w -= count_v; //양이 늑대보다 많다면 늑대의 수를 전체 늑대 카운트에서 빼준다.
            else count_s -= count_o; //늑대가 양과 같거나 많다면 양의 수를 전체 양 카운트에서 빼준다.
        }
    }
    cout << count_s << " " << count_w;
}
```
