#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int n, int left, int right,int to)
{
    if(n==1)
        cout<<left<<' '<<to<<'\n';
    else
    {
        hanoi(n-1,left,to,right);
        cout<<left<<" "<<to<<'\n';
        hanoi(n-1,right,left,to);
    }
}

int main()
{
    int n;
    cin>>n;
    int count = pow(2,n)-1;
    cout<<count<<endl;
    
    hanoi(n,1,2,3);
        
    return 0;
}