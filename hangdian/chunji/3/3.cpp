#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
int xx[21][6]={{9,0,0,0,0,0},
            {7,1,0,0,0,0},
            {5,2,0,0,0,0},
            {3,3,0,0,0,0},
            {1,4,0,0,0,0},
            {6,0,1,0,0,0},
            {1,1,2,0,0,0},
            {3,0,2,0,0,0},
            {5,0,0,1,0,0},
            {1,2,0,1,0,0},
            {2,0,1,1,0,0},
            {3,1,0,1,0,0},
            {3,0,0,0,0,1},
            {1,1,0,0,0,1},
            {0,3,1,0,0,0},
            {0,1,1,1,0,0},
            {0,0,3,0,0,0},
            {0,0,1,0,0,1},
            {0,0,0,0,1,0},
            {4,1,1,0,0,0},
            {2,2,1,0,0,0}};
bool cmp(LL a,LL b){
    return a>b;
}
void solve(){
    LL n;
    cin>>n;
    LL a,b,v;
    vector<vector<LL>> q(10,vector<LL>());
    for(int i=1;i<=n;i++){
        cin>>a>>b>>v;
        LL minn=min(a,b);
        LL maxn=max(a,b);
        if(minn==1){
            if(maxn==1){
                q[1].push_back(v);
            }else if(maxn==2){
                q[2].push_back(v);
            }else if(maxn==3){
                q[3].push_back(v);
            }
        }else if(minn==2){
            if(maxn==2){
                q[4].push_back(v);
            }else if(maxn==3){
                q[6].push_back(v);
            }
        }else if(minn==3){
            q[5].push_back(v);
        }
    }
    for(int i=1;i<=6;i++){
        sort(q[i].begin(),q[i].end(),cmp);
    }
    LL ans=0;
    for(int i=0;i<21;i++){
        LL s=0;
        for(int j=0;j<6;j++){
            int siz=q[j+1].size();
            //cout<<siz<<'\n';
            for(int k=0;k<min(xx[i][j],siz);k++){
                //printf("{%lld,%lld,%lld,%lld}",i,j,k,xx[i][j]);
                s+=q[j+1][k];
            }
        }
        ans=max(ans,s);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}