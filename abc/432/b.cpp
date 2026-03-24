#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int a[10];
void solve()
{
    memset(a,0,sizeof(a));
    LL n;
    cin>>n;
    int tot=0;
    int cnt=0;
    while(n!=0)
    {
        if(n%10!=0)
        {
            tot++;
            a[tot]=n%10;            
        }
        else
        {
            cnt++;
        }
        n=n/10;
    }
    sort(a+1,a+1+tot);
    for(int i=1;i<=tot;i++)
    {
        cout<<a[i];
        if(i==1)
        {
            for(int j=1;j<=cnt;j++)
            {
                cout<<0;
            }
        }
    }
    cout<<'\n';
}
int main()
{
    solve();
    return 0;
}