#include <bits/stdc++.h>

using namespace std;


int main()
{
    // 붙어서 입력이라고 했으니깐
    string board[102];
    int dist[102][102];
    
    queue<pair<int,int>> answer;
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int N,M;
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        cin>>board[i];
    
    for(int i=0; i<N; i++)
        fill(dist[i],dist[i]+M,-1);
    
    dist[0][0] = 1;
    answer.push({0,0});
    
    while(!answer.empty())
    {
        pair<int,int> cur = answer.front();
        answer.pop();
        
        for(int i=0;i<4;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second +dy[i];
            if(nx<0 || N<=nx ||ny<0 ||M<=ny)
                continue;
            if(dist[nx][ny]!=-1 || board[nx][ny] !='1')
                continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            answer.push({nx,ny});
        }
    }
    
    cout<<dist[N-1][M-1];
    
    return 0;
}