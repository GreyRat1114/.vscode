#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
struct node{
    LL x;
    int num;
}a[N];
LL cnt[N];
LL s[N];
int ans[N];
bool cmp(node a,node b){
    return a.x>b.x;
}
void solve(){
    map<LL,int> tr;
    int n;
    cin>>n;
    for(int i=0;i<=n+2;i++){
        cnt[i]=0;
        s[i]=0;
    }    
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].num=i;
        tr[a[i].x]++;
    }
    sort(a+1,a+1+n,cmp);
    

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}