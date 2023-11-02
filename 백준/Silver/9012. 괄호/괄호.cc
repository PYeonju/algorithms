#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin>>N;
    
    string input;
    bool isCheck = false;
    
    while(N--)
    {
        stack<char> temp;
        isCheck = false;
        
        cin>>input;
        
        for(auto c : input)
        {
            if(temp.empty() || c=='(')
                temp.push(c);
            else
            {
                if(c==')' && temp.top() =='(')
                    temp.pop();
                else
                {
                    cout<<"NO\n";
                    isCheck =true;
                    break;
                }
            }
        }
        if(isCheck)
            continue;
        
        if(temp.empty())
            cout<<"YES\n";
        else
            cout<<"NO\n";
        
    }
    
    return 0;
}