#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
using LL=long long;
int a[N];
void solve(){
    int n;
    cin>>n;
    queue<int> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int lt=1;
    int rt=1;
    while(lt<=rt&&lt<=n){
        
        rt=max(rt,lt+a[lt]-1);
        // printf("{%d}",rt);
        if(lt==rt){
            cout<<lt<<'\n';
            return;
        }    
        lt++;

    }
    cout<<n<<'\n';
}
int main(){
    solve();
    return 0;
}
