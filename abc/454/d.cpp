#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    string a,b;
    cin>>a;
    cin>>b;
    LL n=a.size();
    LL m=b.size();
    vector<char> stk1(n+1),stk2(m+1);
    LL tot1=0;
    for(int i=0;i<n;i++){
        tot1++;
        stk1[tot1]=a[i];
        //printf("{%c}",stk1[tot1]);
        if(a[i]==')'&&tot1-3>=1&&stk1[tot1-3]=='('&&stk1[tot1-2]=='x'&&stk1[tot1-1]=='x'){
            //printf("||");
            tot1-=4;
            tot1++;
            stk1[tot1]='x';
            tot1++;
            stk1[tot1]='x';
        }
    }
    LL tot2=0;
    for(int i=0;i<m;i++){
        tot2++;
        stk2[tot2]=b[i];
        if(b[i]==')'&&tot2-3>=1&&stk2[tot2-3]=='('&&stk2[tot2-2]=='x'&&stk2[tot2-1]=='x'){
            tot2-=4;
            tot2++;
            stk2[tot2]='x';
            tot2++;
            stk2[tot2]='x';
        }
    }    
    if(tot1!=tot2){
        cout<<"No"<<'\n';
        return;
    }
    LL tag=1;
    for(int i=1;i<=tot1;i++){
        if(stk1[i]!=stk2[i])tag=0;
    }
    if(tag){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
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