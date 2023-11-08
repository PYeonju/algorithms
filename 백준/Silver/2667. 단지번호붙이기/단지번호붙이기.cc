#include<bits/stdc++.h>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int board[27][27];
int dist[27][27];

int main()
{
    int n;
    
    cin>>n;

    queue<pair<int,int>> Q;
    
    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(int j=0; j<input.size(); j++)
            board[i][j]=input[j]-'0';
    }
    
    int totalCount=0;
    vector<int> answer;
        
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j]==1 && dist[i][j]==0)
            {
                int area=0;
                totalCount++;
                dist[i][j]=1;
                Q.push({i,j});
                
                while(!Q.empty())
                {
                    area++;
                    auto cur = Q.front();
                    Q.pop();
                    
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first +dx[dir];
                        int ny = cur.second +dy[dir];
                        
                        if(nx<0 || n<=nx || ny<0 || n<=ny)
                            continue;
                        if(board[nx][ny]!=1 || dist[nx][ny] == 1)
                            continue;
                        dist[nx][ny]=1;
                        Q.push({nx,ny});
                    }
                }
                answer.push_back(area);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    cout<<totalCount<<"\n";
    for(auto vec:answer)
        cout<<vec<<"\n";
    
    return 0;
}