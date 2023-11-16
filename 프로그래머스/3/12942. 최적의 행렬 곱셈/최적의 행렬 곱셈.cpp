#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[205][205];

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    
    for(int i=1; i<matrix_sizes.size(); i++)
    {
        int end;
        for( int start = 0; start<matrix_sizes.size(); start++)
        {
            end = i + start;
            
            if(end>=matrix_sizes.size())
                break;
            
            dp[start][end] = 2e9;
            for(int sp =start; sp<end; sp++)
            {
                dp[start][end]=min(dp[start][end],dp[start][sp]+dp[sp+1][end]+(matrix_sizes[start][0]*matrix_sizes[sp+1][0]*matrix_sizes[end][1]));
            }
        }
    }
    
    answer = dp[0][matrix_sizes.size()-1];
    
    return answer;
}