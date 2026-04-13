#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1);
    stack<LL> stk;
    queue<LL> qe;    
    for(int i=0;i<n;i++){
        cin>>a[i];
        // stk.push(a[i]);
        // qe.push(a[i]);
    }
    LL op;
    LL x;
    int tag1=1;
    int tag2=1;
    vector<LL> stka;
    vector<LL> qea;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            cin>>x;
            qe.push(x);
            stk.push(x);
        }else{
            if(stk.empty()){
                tag1=0;
            }else{
                stka.push_back(stk.top());
                stk.pop();
            }
            if(qe.empty()){
                tag2=0;
            }else{
                qea.push_back(qe.front());
                qe.pop();
            }
        }
    }
    for(int i=0;i<n;i++){
        if(stka[i]!=a[i]){
            tag1=0;
        }
        if(qea[i]!=a[i]){
            tag2=0;
        }
    }
    if(tag1&&tag2){
        cout<<"both"<<'\n';
    }else if(tag1){
        cout<<"stack"<<'\n';
    }else if(tag2){
        cout<<"queue"<<'\n';
    }else{
        cout<<-1<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}