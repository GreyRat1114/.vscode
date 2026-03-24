#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
void solve(){
    int n;
    cin>>n;
    vector<int> cnt(n+10,0);
    map<int,int> mp;
    LL maxn=0;
    LL minn=1e9;
    int tag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        mp[a[i]]++;
    }
    if(mp[maxn]>=maxn+1){
        cout<<"purple"<<'\n';
    }
    else{
        cout<<"red"<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}