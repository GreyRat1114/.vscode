//cf1627D
#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    vector<LL> vis(1e6+5,0);
    set<LL> ans;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]=1;
        ans.insert(a[i]);
    }
    
    for(LL i=1;i<=1e6;i++){
        LL g=0;
        for(LL j=1;j*i<=1e6;j++){
            if(vis[i*j]){
                if(g==0){
                    g=i*j;
                }else{
                    g=__gcd(g,i*j);
                }
            }
        }
        if(g==i)ans.insert(i);
    }
    cout<<ans.size()-n<<'\n';
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}