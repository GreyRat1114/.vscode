#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
int a[10][10];
char c[105][105];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)%2==0){
                c[i][j]='/';
            }else{
                c[i][j]='\\';
            }            
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<c[i][j];          
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