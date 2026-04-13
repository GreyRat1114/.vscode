#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(5,0)) ;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    sort(a.begin()+1,a.end(),[&](vector<LL> &x,vector<LL> &y){
        if(x[0]+x[1]==y[0]+y[1]){
            if(x[0]==y[0]){
                return x[2]<y[2];
            }
            return x[0]<y[0];
        }
        return x[0]+x[1]<y[0]+y[1];
    });
    LL pos=0;
    for(int i=1;i<=n;i++){
        //printf("{%lld,%lld,%lld}",a[i][0],a[i][1],a[i][2]);
        if(a[i][1]+a[i][0]<pos){
            cout<<"NO"<<'\n';
            return;
        }
        pos=max(pos,a[i][0])+a[i][2];
        //printf("{%lld}",pos);
    }
    cout<<"YES"<<'\n';

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}