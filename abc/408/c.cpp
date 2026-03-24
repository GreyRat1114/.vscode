#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using LL=long long;
int d[N];
void solve(){
    memset(d,0,sizeof(d));
    int n,m;
    int l,r;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        d[l]++;
        d[r+1]--;
    }
    int s=0;
    int minn=1e9;
    for(int i=1;i<=n;i++){
        s+=d[i];
        minn=min(minn,s);
    }
    cout<<minn<<'\n';

}
int main(){
    solve();
    return 0;
}