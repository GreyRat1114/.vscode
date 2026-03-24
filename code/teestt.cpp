#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=1e6+5;
LL seed;
LL read() {
    seed = (seed * 13331 + 23333) % 1000000007;
    return seed;
}
int a[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int p,q;
    cin>>q;
    p=lower_bound(a+1,a+n+1,q)-a;
    cout<<p<<'\n';
    return 0;
}