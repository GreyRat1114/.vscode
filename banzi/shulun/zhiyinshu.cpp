//质因数分解
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> result;
void get(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)n/=i;
            result.emplace_back(i);
        }
    }
    if(n!=1)result.emplace_back(n);
}