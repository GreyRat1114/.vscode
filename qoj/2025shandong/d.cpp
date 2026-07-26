#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(q+1),b(q+1);
    for(int i=1;i<=q;i++){
        cin>>a[i]>>b[i];
    }
    vector<LL> d(n+1,0);
    for(int i=1;i<=q;i++){
        LL cnt=a[i]/n;
        LL p=b[i];
        LL yu=a[i]%n;
        d[0]+=cnt;
        d[n]-=cnt;
        if(p+yu>n){
            LL def=p+yu-n;
            d[p]+=1;
            d[n]-=1;    
            d[0]+=1;
            d[def]-=1;
        }else{
            d[p]+=1;
            d[p+yu]-=1;
        }
    }
    LL ans=0;
    for(int i=0;i<n;i++){
        ans+=d[i];
        cout<<ans<<' ';
    }
    cout<<'\n';    

}
int main(){
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}