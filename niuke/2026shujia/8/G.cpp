#include<bits/stdc++.h>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int a,b,c;
    std::cin>>a>>b>>c;
    std::vector<int>x1,y1,x2,y2;
    for(int i=1;i<=a;i++){
        x1.emplace_back(9);
        x2.emplace_back(9);
    }
    y1.emplace_back(1);
    y2.emplace_back(1);
    for(int i=2;i<=b;i++){
        y1.emplace_back(0);
        y2.emplace_back(0);
    }
    int maxn=std::max(a,b);
    for(int j=a;j<=maxn;j++){
        x2.emplace_back(9);
    }
    for(int j=b;j<=maxn;j++){
        y2.emplace_back(0);
    }
    x2.emplace_back(9);
    y2.emplace_back(1);
    
    for(auto v:x1)std::cout<<v;
    std::cout<<" ";
     for(auto v:y1)std::cout<<v;
    std::cout<<" ";
     for(auto v:x2)std::cout<<v;
    std::cout<<" ";
     for(auto v:y2)std::cout<<v;
    std::cout<<" ";
    return 0;
}