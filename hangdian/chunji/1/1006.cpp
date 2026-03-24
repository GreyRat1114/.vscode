// 交错号了，不好意思
#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
    int n;
    cin >> n;
    vector<pair<LL,LL>> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),[&](const auto& x,const auto& y){return x.first < y.first;});
    vector<pair<LL,LL>> ans;
    int s = a[1].first;
    LL cur = 0;
    for(int i=1;i<=n;i++){
        if(a[i].first == s){
            cur+=a[i].second;
        }
        else{
            ans.push_back({s,cur});
            s = a[i].first;
            cur = a[i].second;
        }
    }
    ans.push_back({s,cur});
    LL cnt = 0;
    for(const auto& [x,y]:ans){
        if(cnt == 0){
            cnt = x + y;
        }
        else{
            cnt = max(cnt,x);
            cnt += y;
        }
    }
    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}