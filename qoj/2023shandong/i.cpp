#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int x[]={2,3,5,6};
void solve(){
    LL a,b;
    cin>>a>>b;
    if(a==0){
        set<LL> st;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    st.insert(x[i]+x[j]+x[k]);
                }
            }
        }
        if(st.count(b)){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }else if(a==1||a==4){
        if(b==4||b==5||b==7||b==8||b==6||b==9||b==10||b==11||b==12){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }else if(a==2||a==5||a==8){
        if(b==2||b==3||b==5||b==6){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }            
    }else if(a==3||a==6||a==9||a==12){
        if(b==0){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }          
    }else{
        cout<<"No"<<'\n';
    }
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