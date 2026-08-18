//cf1547F
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;

void solve(){
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<LL> pa,pb;
    for(LL i=1;i*i<=a;i++){
        if(a%i==0){
            if(i*i==a){
                pa.push_back(i);
            }else{
                pa.push_back(i);
                pa.push_back(a/i);
            }
        }
    }
    for(LL i=1;i*i<=b;i++){
        if(b%i==0){
            if(i*i==b){
                pb.push_back(i);
            }else{
                pb.push_back(i);
                pb.push_back(b/i);
            }
        }
    }
    for(auto i:pa){
        for(auto j:pb){
            LL x=i*j;
            LL y=a*b/(i*j);
            LL cx=c/x*x;
            LL dy=d/y*y;
            if(cx>a&&dy>b){
                cout<<cx<<' '<<dy<<'\n';
                return;
            }
        }
    }
    cout<<-1<<' '<<-1<<'\n';
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