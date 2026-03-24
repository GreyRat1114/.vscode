
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int lowbit(int x){
    return x&-x;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    if(n%2==1){
        a[n]=n;
        a[n-1]=1;
        for(int i=n-2;i>=1;i--){
            a[i]=i^1;
        }
        a[1]=n-1;
        for(int i=1;i<=n;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }else{
        int m=n;
        while(m%2==0){
            m=m/2;
        }

        if(m!=1){
            a[n]=1;
            for(int i=n-1;i>=1;i--){
                a[i]=i^1;
            }
            int x=lowbit(n);
            int tmp=a[x];
            a[x]=n;
            a[1]=tmp;
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            cout<<'\n';
        }else{
            cout<<-1<<'\n';
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