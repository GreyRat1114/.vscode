/*
 * @Author: 'ACmember' '16888571+acmember@user.noreply.gitee.com'
 * @Date: 2026-05-01 15:35:33
 * @LastEditors: 'ACmember' '16888571+acmember@user.noreply.gitee.com'
 * @LastEditTime: 2026-05-01 20:59:28
 * @FilePath: \算法竞赛\acm\计算几何\圆\两个圆相交求面积.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using ld=long double;
using ll=long long ;
const double eps=1e-8;
const long double PI=acos(-1.0);
struct Point{
    ld x,y;
    Point(ld _x = 0,ld _y =0):x(_x),y(_y){}
    ll operator^(const Point& other)const{return 1ll*x*other.y-1ll*other.x*y;}
};
ld dis(Point a,Point b){
    ld dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return dist;
}
ld coss(ld a,ld b,ld c){
    ld m=sqrt(b);
    ld ans=(a*a+b-c*c)/(2.0*a*m);
    
    return ans;
}
//
ld cross(ld r1,ld r2,ld m){
    ld ans=r1*r2*m;
    return ans;
}
void solve(){
    ld x,y,r1;
    ld x1,y1,r2;
    std::cin>>x>>y>>r1;
    std::cin>>x1>>y1>>r2;
    Point ps(x,y),pk(x1,y1);
    ld dm=dis(ps,pk);
    if((r1+r2)*(r1+r2)<=dm){
        std::cout<<std::fixed<<std::setprecision(20)<<0.0<<std::endl;
    }
    else if((r1-r2)*(r1-r2)>=dm){
        ld areaa=PI*r1*r1,areab=PI*r2*r2;
        std::cout<<std::fixed<<std::setprecision(20)<<std::min(areaa,areab);
    }else{
        ld s2=coss(r1,dm,r2);//余弦角
        ld s3=coss(r2,dm,r1);
        ld sk=std::acos(s2);
        ld S1=cross(r1,r1,sin(sk*2));
        ld S3=sk*r1*r1;
        ld sk1=std::acos(s3);
        ld S2=cross(r2,r2,sin(sk1*2));
        ld S4=sk1*r2*r2;
        ld ans=(S1+S2)/2.0;
        ld ms=S3+S4-ans;
        std::cout<<std::fixed<<std::setprecision(20)<<ms<<std::endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T=1;
   // std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}