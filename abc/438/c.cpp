#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int b[N];
void solve(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int tot=0;
    for(int i=1;i<=n;i++){
        tot++;
        b[tot]=a[i];
        if(tot>=4&&b[tot-3]==b[tot-2]&&b[tot-2]==b[tot-1]&&b[tot-1]==b[tot]){
            tot=tot-4;
        }
    }    
    cout<<tot<<'\n';
}
int main(){
    solve();
    return 0;
}