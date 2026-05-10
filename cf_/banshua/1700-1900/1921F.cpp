#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1);
    //printf("{%lld,%lld}",n,q);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    LL s,d,k;
    vector<vector<vector<LL>>> pre(sqrt(n)+10,vector<vector<LL>>(sqrt(n)+10,vector<LL>())),sum(sqrt(n)+10,vector<vector<LL>>(sqrt(n)+10,vector<LL>()));
    for(int i=1;i*i<=n+1;i++){
        //pre[i].push_back(vector<LL>());
        for(int j=0;j<i;j++){
            pre[i][j].push_back(0);
            sum[i][j].push_back(0);
            //printf("{%lld,%lld}",i,j,)
            LL cnt=1;
            LL p=0;
            LL p2=0;
            for(int k=j;k<n;k+=i){
                
                p+=a[k]*cnt;
                pre[i][j].push_back(p);
                
                cnt++;
                p2+=a[k];
                sum[i][j].push_back(p2);
            }
            // for(auto x:pre[i][j]){
            //     printf("{%lld,%lld,%lld}",i,j,x);
            // }
            // cout<<'\n';
        }
    }
    for(int i=1;i<=q;i++){
        cin>>s>>d>>k;
        s--;
        if((k-1)*(k-1)>n){
            //printf("{%lld}",i);
            LL x=s%d;
            LL y=(s-x)/d;
            LL dk=s/d;
            //printf("{%lld,%lld,%lld,%lld,%lld}\n",i,x,y,pre[d][x].back(),pre[d][x][y]);
            LL dd=pre[d][x][y+k]-pre[d][x][y];
            LL s0=(sum[d][x][y+k]-sum[d][x][y])*dk;
            //printf("{%lld,%lld}",dd,s0);
            cout<<dd-s0<<' ';
        }else{
            LL cnt=1;
            LL ans=0;
            for(int j=0;j<k;j++){
                LL pos=s+j*d;
                ans+=cnt*a[pos];
                cnt++;
            }
            cout<<ans<<' ';
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}