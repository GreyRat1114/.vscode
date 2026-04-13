#include<bits/stdc++.h>
using namespace std;
using LL=long long;
// int num[]={}
int yue[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve(){
    string s="5 6 8 6 9 1 6 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2 7 0 5 8 8 5 7 0 9 9 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3";
    vector<LL> a(101);
    int tot=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            tot++;
            a[tot]=s[i]-'0';
            //cout<<a[tot]<<' ';
        }
    }
    LL x=0;
    LL cnt=0;
    set<LL> st;
    for(int i=1;i+7<=tot;i++){
        x=0;
        for(int j=0;j<8;j++){
            x=x*10+a[i+j];
        }
        //printf("{%lld}",x);
        if(x/10000==2023){
            printf("{%lld}",x);
            LL y=(x%10000)/100;
            if(y>=1&&y<=12){
                LL z=(x%100);
                if(z>=1&&z<=yue[y]){
                    if(!st.count(x)){
                        st.insert(x);
                    }
                    
                }
            }
        }
    }
    cout<<st.size()<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}