#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),p(n+1);
    LL p1,p2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]]=i;
    }
    string x;
    cin>>x;
    //vector<pair<LL,LL>> q;
    // auto check=[&](LL l,LL r)->void{
    //     LL mini=min(a[l],a[r]);
    //     LL maxi=max(a[l],a[r]);
    //     for(int i=l+1;i<=r-1;i++){
    //         if(x[i-1]=='0'){
    //             continue;
    //         }
    //         if(a[i]>mini&&a[i]<maxi){
    //             x[i-1]='0';
    //         }
    //     }
    // };
    if(x[p[1]-1]=='1'||x[p[n]-1]=='1'||x[0]=='1'||x[n-1]=='1'){
        cout<<-1<<'\n';
        return;        
    }
    cout<<5<<'\n';
    cout<<1<<' '<<p[1]<<'\n';
    cout<<p[1]<<' '<<n<<'\n';
    cout<<1<<' '<<p[n]<<'\n';
    cout<<p[n]<<' '<<n<<'\n';
    cout<<1<<' '<<n<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}