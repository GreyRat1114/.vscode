#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> a;
vector<LL> p;
void insert(LL x)
{
    for(int i=63;i>=0;i--)
    {
        if(x>>i&1)
        {
            if(p[i])
            {
                x^=p[i];            
            }
            else
            {
                p[i]=x;
                break;
            }
        }
    }
}
void solve(){
    LL n,m;
    cin>>n>>m;
    p.assign(70,0);
    vector<LL> c(m+1);
    for(int i=1;i<=m;i++){
        LL x,y,w;
        cin>>x>>y>>w;
        c[i]=x^y^w;
        insert(c[i]);
    }
    // for(int i=0;i<30;i++){
    //     //cout<<p[i]<<' ';
    // }
    LL ans=1^n;
    for(int i=30;i>=0;i--){
        if(p[i]&&(ans&(1<<i))){
            ans=ans^p[i];
        }
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}