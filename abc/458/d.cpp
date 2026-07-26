#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void solve(){
    LL x;
    LL q;
    cin>>x;
    cin>>q;
    multiset<LL> st1,st2;
    LL cnt=0;
    for(int i=1;i<=q;i++){
        LL a,b;
        cin>>a>>b;
        if(a>=x&&b>=x){
            st2.insert(a);
            st2.insert(b);
            st1.insert(x);
            x=*st2.begin();
            auto it=st2.begin();
            st2.erase(it);
        }else if(a<=x&&b<=x){
            st1.insert(a);
            st1.insert(b);
            st2.insert(x);
            x=*st1.rbegin();
            auto it=st1.end();
            it--;
            st1.erase(it);
            
        }else{
            st1.insert(min(a,b));
            st2.insert(max(a,b));
        }
        cout<<x<<'\n';
    }
    //cout<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
