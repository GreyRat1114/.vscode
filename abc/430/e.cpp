#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ne[N];
string s,p;
int n;
void init(){
    ne[0]=-1;
    for(int i=1,j=-1;i<n;i++){
        while(j!=-1&&p[i]!=p[j+1]){
            j=ne[j];
        }
        if(p[i]==p[j+1]){
            j++;
        }
        ne[i]=j;
    }
}
void solve(){
    string s1;
    cin>>s1;
    s=s1+s1;
    cin>>p;
    n=p.length();
    int m=s.length();
    init();
    int tag=0;
    for(int i=0,j=-1;i<m;i++){
        while(j!=-1&&s[i]!=p[j+1]){
            j=ne[j];
        }
        if(s[i]==p[j+1]){
            j++;
        }
        if(j==n-1){
            tag=1;
            cout<<i-n+1<<'\n';
            return;
        }

    }
    cout<<-1<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}