#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    vector<vector<LL>> a(4,vector<LL>(7,0));
    vector<map<LL,LL>> mp(4);
    LL x;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=6;j++){
            cin>>x;
            mp[i][x]++;
        
        }
    }
    double ans1=1.0*mp[1][4]/6*1.0*mp[2][5]/6*1.0*mp[3][6]/6;
    double ans2=1.0*mp[1][5]/6*1.0*mp[2][6]/6*1.0*mp[3][4]/6;
    double ans3=1.0*mp[1][6]/6*1.0*mp[2][4]/6*1.0*mp[3][5]/6;
    double ans4=1.0*mp[1][4]/6*1.0*mp[2][6]/6*1.0*mp[3][5]/6;
    double ans5=1.0*mp[1][5]/6*1.0*mp[2][4]/6*1.0*mp[3][6]/6;
    double ans6=1.0*mp[1][6]/6*1.0*mp[2][5]/6*1.0*mp[3][4]/6;
    //printf("{%lf,%lf,%lf,%lf,%lf,%lf}",ans1,ans2,ans3,ans4,ans5,ans6);
    double ans=ans1+ans2+ans3+ans4+ans5+ans6;
    cout<<setprecision(20)<<fixed<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}