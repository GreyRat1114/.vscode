#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int c[100][100];
void solve(){
    memset(c,0,sizeof(c));
    LL h,w;
    cin>>h>>w;
    for(int i=1;i<=w;i++){
        c[1][i]=1;
        c[h][i]=1;
    }
    for(int i=1;i<=h;i++){
        c[i][1]=1;
        c[i][w]=1;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(c[i][j]==1){
                cout<<'#';
            }else{
                cout<<'.';
            }
        }
        cout<<'\n';
    }
    
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}