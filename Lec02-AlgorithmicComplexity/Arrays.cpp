#include<iostream>
#include<cmath>
#include<set>
using namespace std;
set<int>s,t;
int main()
{
    int a[100005];
    int n,i,m,j,k;
    bool flag,Flag;
    cin>>n>>m;


    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    flag=false;Flag=false;

    /// 
    /// @
    for( i = 0; i < n;i++)
    {
        t.insert(a[i]);
        if(t.size()==m)
        {
            flag=true;
            j=i;
            break;
        }
    }
    for(i=j;i>=0;i--)
    {
        s.insert(a[i]);
        if(s.size()==m)
        {
            Flag=true;
            k=i;
            break;
        }
    }
    if(flag==true&&Flag==true)
    cout<<k + 1<<" "<<j + 1<<endl;
    else cout<<-1<<" "<<-1<<endl;
}
