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
        string str = "YES";
        stack<char> temp;
        isCheck = false;
        
        cin>>input;
        
        for(auto c : input)
        {
            if(c=='(')
                temp.push(c);
            else if(!temp.empty() && c==')')
                    temp.pop();
            else
            {
                str = "NO";
                break;
            }
        }
        if(!temp.empty())
            str = "NO";
        
        cout<<str<<"\n";
    }
    
    return 0;
}