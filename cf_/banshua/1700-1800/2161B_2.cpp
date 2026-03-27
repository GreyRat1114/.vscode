#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int dx[]={0,1};
int dy[]={-1,0};
int ddx[]={0,2};
int ddy[]={-2,0};
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(n+1,0));
    LL tot=0;
    LL p=0;
    map<LL,vector<LL>> mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j+1]=(s[j]=='.'?0:1);
            if(a[i][j+1]){
                mp[i].push_back(j+1);
                tot++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }
    int tag=1;
    LL px,py;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tag&&a[i][j]){
                tag=0;
                px=i;
                py=j;
            }
            
        }
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}