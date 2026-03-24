#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;

    string s;
    string t;
    cin>>s;
    cin>>t;
    int ans=1e9;
    for(int i=0;i+m<=n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            int x=s[i+j]-'0';
            int y=t[j]-'0';
            cnt=cnt+(x+10-y)%10;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}