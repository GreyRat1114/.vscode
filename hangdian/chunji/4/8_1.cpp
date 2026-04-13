#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL maxn=0;
    LL num;
    LL a,b;
    vector<pair<LL,LL>> op(n+1);
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        op[i].first=a;
        op[i].second=b;
    }
    auto check=[&](LL x)->LL{
        LL xx=x;
        for(int i=1;i<=n;i++){
            LL y=op[i].first;
            LL cnt=0;
            x=xx;
            for(int j=1;j<=4;j++){
                if((x%10)==(y%10)){
                    cnt++;
                }
                x=x/10;
                y=y/10;
            }
            if(cnt!=op[i].second){
                return 0;
            }
        }
        return 1;
    };    
    auto print=[&](LL ans)->void{
        vector<LL> m1(4);
        for(int i=0;i<4;i++){
            m1[i]=ans%10;
            ans=ans/10;
        }  
        for(int i=3;i>=0;i--){
            cout<<m1[i];
        }
        cout<<'\n';
    };    
    for(LL i=0;i<10000;i++){
        if(check(i)){
            print(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}