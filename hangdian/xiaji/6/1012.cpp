// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const LL mod=998244353;
// const LL N=1e7+10;

// void solve(){
//     int n;
//     cin >> n;
//     vector<LL> a(n+1),fa(n+1);
//     for(int i=1;i<=n;i++) cin >> a[i];

//     vector<LL> pre(n+1,0),now(n+1,0);//b的值,与1相连
//     vector<LL> b(n+1,0);

//     for(int i=2;i<=n;i++) cin >> fa[i];

//     auto check = [&]() -> bool{
//         for(int i=1;i<=n;i++){
//             if(pre[i] != now[i]) return false;
//         }
//         return true;
//     };

//     while(1){
//         for(int i=2;i<=n;i++){
//             b[fa[i]] += a[i] + b[i];
//             if(fa[i]==1){
//                 now[i] = a[i] + b[i];
//             }
//             b[i] = 0;
//         }
//         if(check()) break;
//         else{
//             pre = now;
//             now.assign(n+1,0);
//         }
//     }

//     LL ans = 0;

//     for(int i=1;i<=n;i++) ans += pre[i];

//     if(ans == 0){
//         if(b[1] == 0){
//             cout << 0 << "\n";
//         }
//         else if(b[1] > 0){
//             cout << 1 << "\n";
//         }
//         else{
//             cout << -1 << "\n";
//         }
//     }
//     else if(ans > 0){
//         cout << 1 << "\n";
//     }
//     else{
//         cout << -1 << "\n";
//     }
// }

// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int t=1;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;

void solve(){
    int n;
    cin >> n;
    vector<LL> a(n+1);
    vector<vector<int>> edge(n+1);
    LL sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i > 1) sum += a[i];
    }
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        edge[i].push_back(x);
        edge[x].push_back(i);
    }

    vector<LL> num(n+1,-1);
    num[1] = 1;

    auto dfs = [&](auto&& self, int u, int fa) -> void{
        for(const int& v : edge[u]){
            if(v == fa) continue;
            if(v <= u) num[v] = num[u];
            else num[v] = num[u] + 1;
            self(self,v,u);
        }
    };

    dfs(dfs,1,-1);
    LL cur = 0;
    LL maxx = -1;
    for(int i=2;i<=n;i++){
        maxx = max(maxx,num[i]);
        //cout << num[i] << " ";
    }
    //cout << "\n";
    for(int i=2;i<=n;i++){
        cur += a[i] * (maxx - num[i] + 1);
    }

    //cout << sum << " " << cur << "\n";
    if(sum == 0){
        if(cur == 0){
            cout << 0 << "\n";
        }
        else if(cur > 0){
            cout << 1 << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    else if(sum > 0){
        cout << 1 << "\n";
    }
    else{
        cout << -1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}