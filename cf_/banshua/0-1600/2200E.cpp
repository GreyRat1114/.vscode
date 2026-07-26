#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> p;
int isp(LL n){
    set<LL> st;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            while(n%i==0){
                n=n/i;
            }
        } 
    }
    if(st.size()==0){
        p.push_back(*st.begin());
        return 0;
    }else if(st.size()==1){
        p.push_back(*st.begin());
        return 1;
    }else{
        
        return 2;
    }
}
void solve(){
    LL n;
    cin>>n;
    p.clear();
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL tag=1;
    for(int i=1;i<=n-1;i++){
        if(a[i+1]<a[i]){
            tag=0;
            break;
        }
    }
    if(tag){cout<<"Bob"<<'\n';return;}
    LL tag0=1,tag1=1,tag2=0;
    for(int i=1;i<=n;i++){
        LL res=isp(a[i]);
        if(res==2){
            tag2=1;
        }
    }
    if(tag2==1){
        cout<<"Alice"<<'\n';
    }else{
        LL tag=1;
        for(int i=0;i<p.size()-1;i++){
            if(p[i+1]<p[i]){tag=0;break;}
        }
        if(tag){
            cout<<"Bob"<<'\n';
        }else{
            cout<<"Alice"<<'\n';
        }
    }


}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}