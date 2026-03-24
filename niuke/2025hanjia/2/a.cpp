#include<bits/stdc++.h>
using namespace std;
const int N=25;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL x[10];
void solve(){
    cin>>x[1]>>x[2]>>x[3];
    sort(x+1,x+4);
    LL minn=x[1];
    LL maxn=x[3];
    LL y2=x[2]-minn;
    LL y3=x[3]-minn;
    if((y2==y3&&y2==0)||(y2==1&&y3==1)||(y2==1&&y3==0)||(y2==0&&y3==1)){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}