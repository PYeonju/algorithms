#include <bits/stdc++.h>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dist[1001][1001];
int dist2[1001][1001];

int main()
{
    int testCase;
    cin>>testCase;
    
    while(testCase--)
    {
        int w,h;
        cin>>w>>h;
        string board[1001];
        
        queue<pair<int,int>> Q;
        queue<pair<int,int>> Q2;
        
        for(int i=0; i<h; i++)
            cin>>board[i];
        
        for(int i=0; i<h; i++)
        {
            fill(dist[i],dist[i]+w,-1);
            fill(dist2[i],dist2[i]+w,-1);
        }
        
        // Q에 불의 위치와 상근이의 위치를 넣어준다.
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(board[i][j]=='*')
                {
                    Q.push({i,j});
                    dist[i][j]=0;
                }
                else if(board[i][j]=='@')
                {
                    Q2.push({i,j});
                    dist2[i][j]=0;
                }
            }
        }
        
        // 불길의 시간을 구한다.
        while(!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || h<=nx || ny<0 || w<=ny)
                    continue;
                if(board[nx][ny] == '#' || dist[nx][ny] >= 0)
                    continue;
                dist[nx][ny]=dist[cur.first][cur.second]+1;
                Q.push({nx,ny});
            }
        }
        
        bool isCheck=false;
        
        while(!Q2.empty())
        {
            auto cur = Q2.front();
            Q2.pop();
            
            for(int dir=0; dir<4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                // 벗어났다 탈출임
                if(nx<0 || h<=nx || ny<0 || w<=ny)
                {
                    cout<<dist2[cur.first][cur.second]+1<<"\n";
                    isCheck=true;
                    break;
                }
                if(board[nx][ny]=='#' || dist2[nx][ny] >= 0)
                    continue;
                if( dist[nx][ny] != -1 && dist[nx][ny] <= dist2[cur.first][cur.second]+1)
                    continue;
                dist2[nx][ny]=dist2[cur.first][cur.second]+1;
                Q2.push({nx,ny});
            }
          if (isCheck)
             break;
        }
        if(!isCheck)
            cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}