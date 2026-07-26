#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<LL> pre(n+3,0),lst(n+3,0);
    LL mid=n/2+1;
    LL l=0,r=0;
    for(int i=1;i<mid;i++){
        if(i<mid)pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>mid;i--){
        if(i>mid)lst[i]=lst[i+1]+a[i];
    }    
    // if(pre[mid-1]>lst[mid+1]){
    //     cout<<"YES"<<'\n';
    //     return;
    // }else if(pre[mid-1]<lst[mid+1]){
    //     cout<<"NO"<<'\n';
    //     return;
    // }
    if(n%2==1){
        for(int i=1;mid+i<=n;i++){
            if(pre[mid-i]>lst[mid+i]){
                cout<<"YES"<<'\n';
                return;            
            }else if(pre[mid-i]<lst[mid+i]){
                cout<<"NO"<<'\n';
                return;            
            }
        }
        cout<<"NO"<<'\n';    
    }else{
        for(int i=1;mid-i>=2;i++){
            if(pre[mid-i]>lst[mid+i]){
                cout<<"YES"<<'\n';
                return;            
            }else if(pre[mid-i]<lst[mid+i]){
                cout<<"NO"<<'\n';
                return;            
            }
        }
        cout<<"YES"<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}