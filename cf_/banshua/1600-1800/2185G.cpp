#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
const LL mod=998244353;
void solve(){
    int n;
    cin>>n;
    LL l;
    
    vector<map<LL,LL>> a(n+1);

    for(int i=1;i<=n;i++){
        LL x;
        cin>>l;
        for(int j=1;j<=l;j++){
            cin>>x;
            a[i][x]++;
        }
    }
    vector<vector<LL>> mex(n+1);
    LL INF=1e9;
    for(int i=1;i<=n;i++){
        LL nxt=0;
        a[i][INF]=1;
        auto it=a[i].begin();
        while(1){
            LL num=it->first;
            if(num==nxt){
                it++;

            }else if(num!=nxt){
                mex[i].push_back(nxt);
                if(mex[i].size()==2){
                    break;
                }
            }
            nxt=nxt+1;

        }
        a[i].erase(INF);
    }
    map<LL,LL> cnt;
    for(int i=1;i<=n;i++){
        cnt[mex[i][0]]+=mex[i][1]-mex[i][0];
    }
    LL s=0;
    for(int i=1;i<=n;i++){
        s+=mex[i][0];
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        for(auto x:a[i]){
            LL num=x.first;
            LL c=x.second;
            LL pt1,pt2,pt3;
            pt1=cnt[num];
            if(num<=mex[i][0]-1&&c==1){
                pt2=(n-1)*(s-mex[i][0]+num);
            }else{
                pt2=(n-1)*s;
            }
            ans+=(pt1+pt2)*c;
            //printf("{%d,%lld,%lld,%lld,%lld}\n",i,num,pt1,pt2,ans);
        }
        
        //cout<<'\n';
    } 
    cout<<ans<<'\n';
    //printf("{%lld}\n",ans);   
    //cout<<ans<<'\n';
    // for(int i=1;i<=n;i++){
    //     for(auto x:mex[i]){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    // }

}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}