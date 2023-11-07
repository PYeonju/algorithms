#include <bits/stdc++.h>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

string board[1002];
int fireDist[1002][1002];
int jDist[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R,C;
    cin>>R>>C;
    
    queue<pair<int,int>> Q;
    queue<pair<int,int>> Q2;
    
    for(int i=0; i<R; i++)
    {
        fill(fireDist[i],fireDist[i]+C,-1);
        fill(jDist[i],jDist[i]+C,-1);
    }
    
    for(int i=0; i<R; i++)
        cin>>board[i];
        
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
           if(board[i][j]=='F')
           {
               Q.push({i,j});
               fireDist[i][j]=0;
           }
           if(board[i][j]=='J')
           {
               Q2.push({i,j});
               jDist[i][j]=0;
           }
        }
    }

    // 불의 시간 구하기
          
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        for(int dir=0; dir<4; dir++)
        {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];
                        
                if(nx<0|| R<=nx || ny<0 || C<=ny)
                    continue;
                if(board[nx][ny]=='#' || fireDist[nx][ny] >= 0)
                    continue;
                fireDist[nx][ny] = fireDist[cur.first][cur.second]+1;
                Q.push({nx,ny});
          }
    }
    

    // 지훈이가 이동하는 거리 보기
    while(!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();
        for(int dir=0; dir<4; dir++)
        {
             int nx = cur.first + dx[dir];
             int ny = cur.second + dy[dir];
                        
             if(nx<0|| R<=nx || ny<0 || C<=ny)
             {
                 // 범위를 벗어난것은 탈출이다.
                 cout<<jDist[cur.first][cur.second]+1;
                 return 0;
             }
            if(board[nx][ny]=='#' || jDist[nx][ny] >= 0)
                continue;
            // 불 전파 시간보다 크면 이미 불길이 있는 것이므로 불가
            if(fireDist[nx][ny] != -1 && fireDist[nx][ny] <= jDist[cur.first][cur.second]+1)
                continue;
             jDist[nx][ny] = jDist[cur.first][cur.second]+1;
             Q2.push({nx,ny});
        }
    }
    cout<<"IMPOSSIBLE";
}