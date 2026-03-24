#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
struct node{
    int x,y;
}a[N];
bool cmp(node x,node y){
    return x.x<y.x;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=3;i++){
        cout<<a[i].y<<' ';
    }
    cout<<'\n';
}
int main(){
    solve();
    return 0;
}