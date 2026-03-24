#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
LL dp[N],from[N],sub[N];

LL a[N];
void solve(){
    int n;
    cin>>n;
    LL s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(s%n!=0){
        cout<<-1<<'\n';
        return;
    }
    LL avg=s/n;
    for(int sta=1;sta<(1<<n);sta++){
        dp[sta]=n+1;
        from[sta]=-1;
        sub[sta]=0;
        for(int i=0;i<n;i++){
            if(sta>>i&1){
                sub[sta]+=(a[i]-avg);
            }
        }
        LL cost=sub[sta]==0?0:1;
        for(int i=0;i<n;i++){
            if(sta>>i&1){
                LL fro=sta^(1<<i);
                if(dp[sta]>dp[fro]+cost){
                    dp[sta]=dp[fro]+cost;
                    from[sta]=i;
                }
            }
        }
    }
    LL cur=(1<<n)-1;
    vector<array<LL,3>> ans;
    while(cur!=0){
        vector<array<LL,2>> vec;
        do{
            LL fro=from[cur];
            vec.push_back({fro,a[fro]});
            cur-=(1<<fro);

        }while(sub[cur]!=0);
        sort(vec.begin(),vec.end(),[&](array<LL,2>l,array<LL,2>r){
            return l[1]>r[1];
        });
        LL cost =vec[0][1]-avg;
        for(int i=1;i<vec.size();i++){
            ans.push_back({vec[i-1][0],vec[i][0],cost});
            cost+=vec[i][1]-avg;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [x,y,z]:ans){
        cout<<x+1<<' '<<y+1<<' '<<z<<'\n';
    }
}
signed main(){
    solve();
    return 0;
}