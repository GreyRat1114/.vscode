#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    /*if(k == 1){
        cout << "-1" << "\n";
        return;
    }*/
   /*if(n >= k){
        cout << "-1" << "\n";
        return;
    }*/
    set<int> now;
    vector<int> ans;
    int cnt = 0;
    /*while(cnt + i < k){
        ans.push_back(i);
        cnt+=i;
        i++;
    }
    cnt = 0;
    for(int i=ans.size()-1;i>=0;i--){
        cnt += ans[i];
        now.insert(cnt % k);
    }*/
    for(int i=1;;i++){
        int r = i % k;
        if(r == 0) continue;
        if(now.find(k-r) == now.end()){
            ans.push_back(i);
            //cerr << i << " ";
            set<int> s;
            for(const auto& x: now){
                s.insert((x + r) % k);      
            }
            now = s;
            now.insert(r);
        }
        if(ans.size() == n) break;
        if(now.size() == k-1) break;
    }
    for(const auto& x: ans) cout << x << " ";cout << "\n";
}

int main(){
   // ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}