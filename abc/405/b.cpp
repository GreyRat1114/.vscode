#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
void solve(){
    map<int,int> tr;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(tr[a[i]]==0){
            tr[a[i]]=i;
        }
    }
    if(tr.size()<m){
        cout<<0<<'\n';
        return;
    }
    int maxn=0;
    for(auto x:tr){
        maxn=max(maxn,x.second);
    }
    cout<<n-maxn+1<<'\n';
}
int main(){
    solve();
    return 0;
}