#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=1e3+5;
const int M=255;
#define LL long long
LL n,m;

void solve(int t){
    int c;
    cin>>c;
    string s1,s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    
    //int tp=(c/4)*2+2;
    int tag=0;
    for(int i=1;i<=100;i++){
        string str1="";
        string str2="";
        // cout<<str1<<'\n';
        for(int j=0;j<c;j++){
            if(j%2==0){
                str1+=s2[j/2];
            }else{
                str1+=s1[j/2];
            }
        }
        for(int j=c;j<2*c;j++){
            if(j%2==0){
                str2+=s2[j/2];
            }else{
                str2+=s1[j/2];
            }
        }
        s1=str1;
        s2=str2;
        string s=s1+s2;
        if(s==s3){
            cout<<t<<' '<<i<<'\n';
            tag=1;
            return;
        }
        // cout<<str1<<'\n';
        // cout<<str2<<'\n';
    }
    cout<<t<<' '<<-1<<'\n';
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}