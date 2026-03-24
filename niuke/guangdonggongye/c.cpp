#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const double M=1e9;
using LL=long long;
LL a[N];
void solve(){
    int n,q;
    LL x;
    LL z;
    cin>>n>>q;
    int tot=0;
    int tag=0;
    for(int i=1;i<=n;i++){
        cin>>z;
        if(z==1){
            tag=1;
            continue;
        }
        tot++;
        a[tot]=z;
    }
    set<LL> st;
    for(int i=1;i<=tot;i++){
        LL s=a[i];
        st.insert(s);
        for(int j=i+1;j<=tot;j++){
            double y=M/a[j];
            if(y<s){
                break;
            }
            s=s*a[j];
            if(s>1e9){
                break;
            }
            st.insert(s);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x;
        if(x==1){
            if(tag){
                cout<<"Yes"<<'\n';
            }
            else{
                cout<<"No"<<'\n';
            }
            continue;
        }
        if(st.count(x)){
            cout<<"Yes"<<'\n';
        }
        else{
            cout<<"No"<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}