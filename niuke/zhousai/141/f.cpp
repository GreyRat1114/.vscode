#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<vector<LL>> cnt(30,vector<LL>(n+1,0)),ans(30,vector<LL>(n+1,0)),psum(30,vector<LL>(n+1,0));
    for(int i=0;i<26;i++){
        for(int j=1;j<=n;j++){
            cnt[i][j]=cnt[i][j-1];
            if(s[j-1]-'a'==i){
                cnt[i][j]++;
            }
        }        
    }
    for(int i=0;i<26;i++){
        for(int j=1;j<=n;j++){
            psum[i][j]=psum[i][j-1];
            if(s[j-1]-'a'==i){
                psum[i][j]+=j;
            }
        }
    }    
    for(int i=0;i<26;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=ans[i][j-1];
            if(s[j-1]-'a'==i){
                ans[i][j]+=cnt[i][j-1]*(j-1)-psum[i][j-1];
            }
            
        }    
        //cout<<'\n';
    }    
    for(int i=1;i<=q;i++){
        LL l,r,x;
        cin>>l>>r>>x;
        if(x==1){
            LL ans1=0;
            for(int j=0;j<26;j++){
                ans1+=cnt[j][r]-cnt[j][l-1];
            }            
            cout<<ans1<<'\n';
        }else if(x==2){
            LL ans1=0;
            for(int j=0;j<26;j++){
                LL d=cnt[j][r]-cnt[j][l-1];
                ans1+=(d-1)*d/2;
            }            
            cout<<ans1<<'\n';            
        }else{
            LL ans1=0;
            for(int j=0;j<26;j++){
                ans1+=ans[j][r]-ans[j][l-1]-(cnt[j][l-1]*((psum[j][r]-psum[j][l-1])-(cnt[j][r]-cnt[j][l-1]))-psum[j][l-1]*(cnt[j][r]-cnt[j][l-1]));
            }            
            cout<<ans1<<'\n';
        }
    }
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}