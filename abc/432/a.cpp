#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int a[4];
void solve()
{
    a[0]=0;
    for(int i=1;i<=3;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+3);
    for(int i=3;i>=1;i--)
    {
        cout<<a[i];
    }
    cout<<'\n';
}
int main()
{
    solve();
    return 0;
}