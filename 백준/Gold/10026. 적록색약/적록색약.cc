#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

string board[101];
int n;

int countArea(char input)
{
    queue<pair<int,int>> Q;
    int dist[101][101];
    int count = 0;
    
    for(int i=0; i<n; i++)
        fill(dist[i],dist[i]+n, 0);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]==input && dist[i][j]==0)
            {
                count++;
                
                dist[i][j] = 1;
                Q.push({i,j});

                while(!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    
                    for(int dir = 0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        
                        if(nx<0 || n<=nx || ny<0 || n<=ny )
                            continue;
                        if(dist[nx][ny] != 0 || board[nx][ny] != input)
                            continue;
                        dist[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
    
    return count;
}

int main()
{
    cin>>n;
    
    for(int i=0; i<n; i++)
        cin>>board[i];
    
    // 총 4번을 돌려야 한다.
    int RCount = countArea('R');
    int GCount = countArea('G');
    int BCount = countArea('B');
    
    queue<pair<int,int>> Q;
    
    int dist[101][101];
    int RGCount = 0;
    
    for(int i=0; i<n; i++)
        fill(dist[i],dist[i]+n, 0);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dist[i][j]==0)
            {
                if(board[i][j]=='R' || board[i][j]=='G')
                {
                    RGCount++;
                
                    dist[i][j] = 1;
                    Q.push({i,j});

                    while(!Q.empty())
                    {
                        auto cur = Q.front();
                        Q.pop();
                        
                        for(int dir = 0; dir<4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            
                            if(nx<0 || n<=nx || ny<0 || n<=ny )
                                continue;
                            if(dist[nx][ny] != 0 || board[nx][ny] == 'B')
                                continue;
                            dist[nx][ny]=1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    
    cout<<RCount+GCount+BCount<<" "<<RGCount+BCount;
    
    return 0;
}