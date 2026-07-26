#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void solve(){
    LL h,w;
    cin>>h>>w;

    vector<vector<LL>> a(h+1,vector<LL>(w+1,0));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            for(int k=0;k<4;k++){
                LL x=i+dx[k];
                LL y=j+dy[k];
                if(x<1||x>h||y<1||y>w)continue;
                a[i][j]++;
            }
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }

}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}