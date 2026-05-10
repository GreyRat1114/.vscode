#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n;
vector<LL> s;
int lowbit(int x)
{
    return x&-x;
}
void change(int x,int k)
{
    while(x<=n)
    {
        s[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int t=0;
    while(x)
    {
        t+=s[x];
        x-=lowbit(x);
    }
    return t;
}