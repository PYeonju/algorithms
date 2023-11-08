#include <bits/stdc++.h>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int board[102][102];
int dist[102][102];

int main()
{
    int m,n,k;
    cin>>m>>n>>k;
   
    queue<pair<int,int>> Q;
    
    while(k--)
    {
        int left,bottom,right,top;
        cin>>left>>bottom>>right>>top;
        
        for(int i=bottom; i<top; i++)
        {
            // 직사각형인 부분을 1로 바꾼다.
            for(int j=left; j<right; j++)
                board[i][j]=1;
        }
    }
    
    int totalCount=0;
    vector<int> answer;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]==0 && dist[i][j]==0)
            {
                int area = 0;
                totalCount++;
                
                Q.push({i,j});
                dist[i][j]=1;
                
                while(!Q.empty())
                {
                    area++;
                    auto cur = Q.front();
                    Q.pop();
                    
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first +dx[dir];
                        int ny = cur.second +dy[dir];
                        
                        if(nx<0|| m<=nx|| ny<0|| n<=ny)
                            continue;
                        if(board[nx][ny]==1 || dist[nx][ny]==1)
                            continue;
                        dist[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
                answer.push_back(area);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    cout<<totalCount<<"\n";
    for(auto vec : answer)
        cout<<vec<<" ";

    return 0;
}