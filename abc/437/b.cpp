#include<bits/stdc++.h>
using namespace std;
const int N=15;
using LL=long long;
int a[N][N];
int b[105];
void solve(){
    int h,w,n;
    cin>>h>>w>>n;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int maxn=0;
    for(int i=1;i<=h;i++){
        int tot=0;
        for(int j=1;j<=w;j++){
            for(int k=1;k<=n;k++){
                if(a[i][j]==b[k]){
                    tot++;
                    break;
                }
            }
        }
        maxn=max(maxn,tot);

    }
    cout<<maxn<<'\n';
}
int main(){
    solve();
    return 0;
}
