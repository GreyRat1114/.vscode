// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const LL mod=998244353;
// const LL N=1e7+10;
// using i128=__int128_t;

// void solve(){
//     LL n,k,m,q;
//     cin>>n>>k>>m>>q;

//     map<string,LL> b;
//     map<string,LL> vis;
//     vector<int> ans;
//     pair<string,LL> pre={"",0};
//     map<string,LL> ok;
//     for(int i=1;i<=n;i++){
//         string s;
//         cin >> s;
//         if(s!=pre.first){
//             pre={s,i};
//         }
//         //printf("{%lld,%lld}",i,i-pre.second);
//         if(ok[s]&&(i-b[s]-1>=m)&&vis[s]<q){
//             ans.push_back(i);
//         }
//         if(i-pre.second>=k){
//             ok[pre.first]=1;
//             //printf("{%lld}",i);
//         }
//         if(b[s]==0){
//             b[s] = i;
//         }  
//         vis[s]++;
//     }
    
//     if(ans.empty()){
//         cout << "empty" << "\n";
//     }
//     else{
//         for(int& x : ans) cout << x << " ";
//         cout << "\n";
//     }
// }
// int main(){
//     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int t=1;
//     cin>>t;
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
using i128=__int128_t;

void solve(){
    LL n,k,m,q;
    cin>>n>>k>>m>>q;

    map<string,LL> a,b,c;
    vector<int> ans;
    pair<string,LL> pre={"",0};

    for(int i=1;i<=n;i++){
        string s;
        cin >> s;

        if(a[s] > 0 && c[s] >= k && i - b[s] - 1 >= m && a[s] < q){
            ans.push_back(i);
        }

        if(a[s] == 0){
            b[s] = i;
        }
        a[s]++;

        if(pre.first == s){
            pre.second++;
            c[s] = max(c[s],pre.second);
        }
        else{
            pre = {s,1};
            if(c[s] == 0){
                c[s] = 1;
            }
        }
    }
    
    if(ans.empty()){
        cout << "empty" << "\n";
    }
    else{
        for(int& x : ans) cout << x << " ";
        cout << "\n";
    }
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