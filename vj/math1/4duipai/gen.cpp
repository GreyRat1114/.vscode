#include<bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
int main(){
    int t=2000;

    cout<<t<<'\n';
    for(int i=1;i<=t;i++){
        int x=rnd()%1000000+1;
        int y=rnd()%9+1;        
        if(x%5==0||x%2==0){
            continue;
        }
        cout<<x<<' '<<y<<'\n';        
    }
    return 0;
}