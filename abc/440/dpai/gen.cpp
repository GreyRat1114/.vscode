#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
using LL=long long;
const LL mod=1e9;
int main(){
    int n=rnd()%10000+1;
    int q=rnd()%10000+1;
    cout<<n<<' '<<q<<'\n';
    set<LL> tr;
    for(int i=1;i<=n;){
        LL a=rnd()%mod+1;
        if(tr.count(a)){
            continue;
        }
        
        tr.insert(a);
        // printf("{%lld %d}\n",a,i);
        cout<<a<<' ';
        i++;
    }
    cout<<'\n';
    for(int i=1;i<=q;i++){
        LL x=rnd()%mod+1;
        LL y=rnd()%mod+1;       
        cout<<x<<' '<<y<<'\n'; 
        // if(x%5==0||x%2==0){
        //     continue;
        // }
        // cout<<x<<' '<<y<<'\n';        
    }
    return 0;
}