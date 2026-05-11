// 用于求解两个集合的数是否相同问题，给每个数赋一个哈希值，如果两个集合里面哈希值之和相等
// 那么这两个集合即是相同的
// abc 367 f
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
using ull=unsigned long long;
const LL N=2e5+5;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<ull> a(n+1);
    vector<ull> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    vector<ull> h1(n+1),h2(n+1);
    for(int i=1;i<=n;i++){
        h1[i]=rng();
    }    
    vector<ull> pre1(n+1,0),pre2(n+1,0);
    for(int i=1;i<=n;i++){
        pre1[i]=pre1[i-1]+h1[a[i]];
        pre2[i]=pre2[i-1]+h1[b[i]];
    }    

    for(int i=1;i<=q;i++){
        LL l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(r1-l1!=r2-l2){
            cout<<"No"<<'\n';
            continue;
        }
        ull s1=pre1[r1]-pre1[l1-1];
        ull s2=pre2[r2]-pre2[l2-1];
        if(s1==s2){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }
    

}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}