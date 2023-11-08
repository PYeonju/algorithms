#include <bits/stdc++.h>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int board[102][102];

int main()
{
    int n;
    int h=0;
    int maxH=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>board[i][j];
            maxH = max(maxH,board[i][j]);
        }
    }
    
    int maxArea=0;
    
    // 하나씩 검사해야하므로 
    while(h <= maxH)
    {
        int area=0;
        queue<pair<int,int>> Q;
        int dist[102][102];
        for(int i=0; i<n; i++)
            fill(dist[i],dist[i]+n,0);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(h<board[i][j] && dist[i][j]==0)
                {
                    area++;
                    dist[i][j]=1;
                    Q.push({i,j});
                    
                    while(!Q.empty())
                    {
                        auto cur = Q.front();
                        Q.pop();
                        
                        for(int dir=0; dir<4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            
                            if(nx<0 || n<=nx || ny<0|| n<=ny)
                                continue;
                            if(board[nx][ny]<=h || dist[nx][ny]!=0)
                                continue;
                            dist[nx][ny]=1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        maxArea = max(area,maxArea);
        h++;
    }
    
    cout<<maxArea;
    
    return 0;
}