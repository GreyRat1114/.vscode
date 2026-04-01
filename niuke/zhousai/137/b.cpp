#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    string s;
    deque<char> q;
    cin>>s;
    int tag=0;
    for(int i=0;i<n;i++){
        if(s[i]=='!'){
            tag=tag^1;
        }else if(s[i]=='-'){
            if(q.empty()){
                continue;
            }
            if(tag==0){
                q.pop_back();
            }else{
                q.pop_front();
            }
        }else{
            if(tag==0){
                q.push_back(s[i]);
            }else{
                q.push_front(s[i]);
            }
        }

    }
    if(q.empty()){
        cout<<"Empty"<<'\n';
        return;
    }
    while(!q.empty()){
        cout<<q.front();
        q.pop_front();
    }
    cout<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}