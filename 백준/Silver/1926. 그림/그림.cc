#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,n;
    
    cin>>m>>n;
    int board[502][502]={};
    bool vis[502][502]={false};
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    // Input Board를 채워준다.
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            cin>>board[i][j];
    }
    
    
    int maxDraw = 0;
    int countDraw = 0;
    
    // 시작점을 찾기
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(vis[i][j] || board[i][j]==0)
                continue;

            countDraw++;
            queue<pair<int,int>> answer;
              
            vis[i][j] = true;
            answer.push({i,j});
                
            int count=0;
                
            while(!answer.empty())
            {
                pair<int, int> cur = answer.front();
                answer.pop();
                count++;
                    
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<0 || m<=nx || ny<0 || n<=ny)
                        continue;
                     if(vis[nx][ny] || board[nx][ny] !=1)
                        continue;
                     vis[nx][ny]=1;
                        answer.push({nx,ny});
                    }
                }
             maxDraw=max(count,maxDraw);
        }    
    }
    
    cout<<countDraw<<'\n'<<maxDraw;
    
    return 0;
}