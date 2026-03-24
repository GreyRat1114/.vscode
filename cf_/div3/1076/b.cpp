#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
void solve(){
    LL n,s,x;
    cin>>n;
    LL max1=0,max2=0;
    int p1,p2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL y=n;
    int l=0;
    for(int i=1;i<=n;i++){
        if(a[i]<y&&l==0){
            l=i;
        }else if(a[i]==y){
            if(l){
                for(int j=1;j<=l-1;j++){
                    cout<<a[j]<<' ';
                }
                for(int j=i;j>=l;j--){
                    cout<<a[j]<<' ';
                }
                for(int j=i+1;j<=n;j++){
                    cout<<a[j]<<' ';
                }
                cout<<'\n';
                return;
            }else{
                y--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}