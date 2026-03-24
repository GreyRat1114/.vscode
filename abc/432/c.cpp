#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
LL gcd(LL a,LL b)
{
    LL t;
    while(b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
void solve()
{
    LL n,x,y;
    cin>>n>>x>>y;
    LL s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(x==y)
    {
        cout<<s<<'\n';
        return;
    }
    sort(a+1,a+1+n);
    LL sum=a[1];
    LL gd=gcd(x,y);
    LL mb=x*y/gd;
    LL xg=mb/x;
    LL yg=mb/y;
    LL d=abs(xg-yg);
    // cout<<xg<<yg<<d<<'\n';
    for(int i=2;i<=n;i++)
    {
        LL dist=a[i]-a[1];
        if(dist%d!=0)
        {
            cout<<-1<<'\n';
            return;            
        }

        if(a[1]-(dist/d)*yg<0)
        {
            // printf("{%lld,%lld}",dist,i);
            cout<<-1<<'\n';
            return;
        }
    
        sum+=a[1]-(dist/d)*yg;
    }
    cout<<sum<<'\n';
}
int main()
{
    solve();
    return 0;
}