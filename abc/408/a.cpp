#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int a[N];
void solve(){
    int n,s;
    int x,y;
    y=0;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x-y>s){
            cout<<"No"<<'\n';
            return;
        }
        y=x;
    }
    cout<<"Yes"<<'\n';

}
int main(){
    solve();
    return 0;
}