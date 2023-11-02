#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    
    string input;
    
    int count = 0;
    
    while(N--)
    {
        stack<char> temp;
        
        cin>>input;
        
        for(auto c : input)
        {
            if(temp.empty())
                temp.push(c);
            else
            {
                if(temp.top()==c)
                    temp.pop();
                else
                    temp.push(c);
            }
        }
        if(temp.empty())
            count++;
    }
    
    cout<<count;
    
    return 0;
}