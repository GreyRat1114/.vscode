#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    LL maxn=0;
    LL minn=1e10;    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }

    vector<LL> ans;
    while(maxn!=minn){
        if((maxn%2==0)&&(minn%2==1)){
            for(int i=1;i<=n;i++){
                a[i]=(a[i]+1)/2;
            }        
            ans.push_back(1);
        }else{
            ans.push_back(0);
            for(int i=1;i<=n;i++){
                a[i]=(a[i])/2;
            }    
        }
        maxn=0;
        minn=1e10;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
            minn=min(minn,a[i]);
        }        
    }
    cout<<ans.size()<<'\n';
    if(ans.size()<=n&&ans.size()!=0){
        for(auto x:ans){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}