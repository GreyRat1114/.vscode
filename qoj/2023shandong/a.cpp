#include<bits/stdc++.h>
using namespace std;
using LL=long long;
bool cmp(pair<LL,LL> a,pair<LL,LL> b){
    return a.first<b.first;
}
void solve(){
    LL n,k;
    cin>>n>>k;
    LL pre=0;
    vector<pair<LL,LL>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin()+1,a.end(),cmp);
    LL s=0;
    for(int i=1;i<=n;i++){
        s+=(a[i].first-pre)*k;
        if(s<a[i].second){
            cout<<"No"<<'\n';
            return;
        }else{
            s-=a[i].second;
        }
        pre=a[i].first;
    }
    cout<<"Yes"<<'\n';
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