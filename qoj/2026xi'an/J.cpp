#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin()+1,a.end(),[&](const auto& x,const auto& y){return x.first < y.first;});
    int pos = -1;
    int len = 0;
    auto se = [&](int x,int tar)->int{
        if(x > n) return -1;
        int l = x;
        int r = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid].first >= tar) r = mid - 1;
            else l = mid + 1;
        }
        if(r < x) return 0;
        return r;
    };

    for(int i=1;i<n;i++){
        int x = a[i].first + a[i+1].first;
        int r = se(i+2,x);
        int cur = r - i + 1;
        if(cur > len){
            len = cur;
            pos = i;
        }
    }

    if(len == 0){
        cout << 0 << "\n";
        return;
    }
    else{
        cout << len << " ";
        vector<pair<int,int>> ans;
        for(int i=pos;i<pos+len;i++){
            ans.push_back(a[i]);
        }
        sort(ans.begin(),ans.end(),[&](const auto& x,const auto& y){return x.second < y.second;});
        for(const auto& [x,y] : ans) cout << x << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}