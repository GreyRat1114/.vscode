#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e9;
int main(){
    int n=rnd()%10+1;
    int m=rnd()%50+1;
    //int q=rnd()%10000+1;
    //cout<<n<<' '<<q<<'\n';
    for(int i=0;i<n;i++){
        int c=rnd()%26;
        char c1=(char)(c+'a');
        cout<<c1;
    }
    cout<<'\n';
    for(int i=0;i<m;i++){
        int c=rnd()%26;
        char c1=(char)(c+'a');
        cout<<c1;
    }    
    cout<<'\n';
    return 0;
}