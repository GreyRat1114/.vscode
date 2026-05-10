#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=1e9;
LL maxn[2]={0,0};
void solve(){
    LL n;
    cin>>n;
    
    vector<LL> a(n+1);
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    LL tag=0;
    if(s%n){
        cout<<-1<<'\n';
        return;
    }

    LL avg=s/n;
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    if(n==2){
        if(a[1]<=a[2]){
            LL ans=abs(a[1]-avg);
            cout<<ans<<'\n';            
        }else{
            cout<<-1<<'\n';
        }
        return;


    }    
    //vector<map<LL,vector<LL>>> mp(2);
    vector<vector<LL>>mp(2);
    for(int i=1;i<=n;i++){
        if(i==n){
            if(a[i]!=avg){
                cout<<-1<<'\n';
                return;                
            }
            continue;
        }
        if(a[i]>avg){
            cout<<-1<<'\n';
            return;            
        }
        LL d=avg-a[i];
        a[i+1]-=d;
        a[i]+=d;
        mp[tag].push_back(d);
        //mp[tag][d].push_back(i);
        //maxn[tag]=max(maxn[tag],d);
        tag=tag^1;
    }
    //vector<vector<LL>> c(2,vector<LL>(n+1,0));
    LL ans=0;
    for(int i=0;i<=1;i++){
        //c[i][0]=0;
        ans+=mp[i][0];
         
     //   std::cerr<<mp[i].size()<<endl;
        for(int j=1;j<mp[i].size();j++){
            LL d=mp[i][j]-mp[i][j-1];
            if(d>0){
                ans+=d;
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}