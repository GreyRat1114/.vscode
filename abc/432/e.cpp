#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define int long long
const int N=5e5+5;
int m;
int n,s[N],s1[N];
int lowbit(int x)
{
    return x&-x;
}
void change(int x,int k)//向后修
{
    while(x<=N)
    {
        s[x]+=k;
        x+=lowbit(x);
    }
}
int query(int x)//向前查
{
    int t=0;
    while(x)
    {
        t+=s[x];
        x-=lowbit(x);
    }
    return t;
}
void change1(int x,int k)//向后修
{
    while(x<=N)
    {
        s1[x]+=k;
        x+=lowbit(x);
    }
}
int query1(int x)//向前查
{
    int t=0;
    while(x)
    {
        t+=s1[x];
        x-=lowbit(x);
    }
    return t;
}
int a[N];
void solve(){
    memset(s,0,sizeof(s));
    memset(s1,0,sizeof(s1));
    int q;
    cin>>n>>q;
    int x;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m=max(m,a[i]);
    }
    vector<int> cnt(N,0);

    for(int i=1;i<=n;i++){
        x=a[i];
        change1(x+1,1);
        change(x+1,x);    
    //     for(int i=1;i<=m+10;i++){
    //     // printf("{%d}",query1(i)-query1(i-1));
    // }
    // cout<<'\n';
    }    
    // for(int i=1;i<=m+10;i++){
    //     printf("{%d}",query1(i)-query1(i-1));
    // }
    // cout<<'\n';
    int l,r;
    int op;
    for(int i=1;i<=q;i++){
        cin>>op>>l>>r;
        if(op==1){
            x=a[l];
            m=max(m,a[i]);
            a[l]=r;
            change(x+1,-x);
            change1(x+1,-1);
            change(r+1,r);    
            change1(r+1,1);      
        }
        else{
            if(l>=r){
                cout<<l*n<<'\n';
            }
            else{
                int s1=query(r+1);
                int s2=query(l);
                int s3=query1(l)*l;
                int s4=(query1(N)-query1(r+1))*r;
                // printf("{%d,%d,%d}",query1(l-1),query1(m+5),query1(r+1));
                cout<<s1-s2+s3+s4<<'\n';    
            }
        }
    }
}
signed main(){
    solve();
    return 0;
}