#include<bits/stdc++.h>
using namespace std;
#define shoupai pair<int,vector<int> >
struct card{
    int Number;
    char Color;
    void init(string s){
        char c0=s[0],c1=s[1];
        if(isdigit(c0))Number=c0-'0';
        else{
            if(c0=='T')Number=10;
            if(c0=='J')Number=11;
            if(c0=='Q')Number=12;
            if(c0=='K')Number=13;
            if(c0=='A')Number=14;
        }
        Color=c1;
    }
};
bool cmp(card x,card y){return x.Number>y.Number;}
vector<int> TongHua(vector<card>v){
    for(int i=1;i<v.size();++i)if(v[i].Color!=v[0].Color)return {};
    vector<int>rt;rt.clear();
    for(int i=0;i<v.size();++i)rt.push_back(v[i].Number);
    sort(rt.rbegin(),rt.rend());
    return rt;
}
vector<int> Shun(vector<card>v){
    if(v[0].Number==14 and v[1].Number==5 and v[2].Number==4 and v[3].Number==3 and v[4].Number==2)return {5,4,3,2,1};
    if(v[0].Number-1==v[1].Number and v[1].Number-1==v[2].Number and v[2].Number-1==v[3].Number and v[3].Number-1==v[4].Number)
        return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
    return {};
}
vector<int> SiTiao(vector<card>v){
    if(v[0].Number==v[1].Number and v[1].Number==v[2].Number and v[2].Number==v[3].Number)
        return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
    if(v[4].Number==v[1].Number and v[1].Number==v[2].Number and v[2].Number==v[3].Number)
        return {v[4].Number,v[1].Number,v[2].Number,v[3].Number,v[0].Number};
    return {};
}
vector<int> HuLu(vector<card>v){
    if(v[0].Number==v[1].Number and v[1].Number==v[2].Number and v[3].Number==v[4].Number)
        return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
    if(v[4].Number==v[3].Number and v[3].Number==v[2].Number and v[1].Number==v[0].Number)
        return {v[4].Number,v[3].Number,v[2].Number,v[1].Number,v[0].Number};
    return {};
}
vector<int> SanTiao(vector<card>v){
    if(v[0].Number==v[1].Number and v[1].Number==v[2].Number)
        return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
    if(v[1].Number==v[2].Number and v[2].Number==v[3].Number)
        return {v[1].Number,v[2].Number,v[3].Number,v[0].Number,v[4].Number};
    if(v[2].Number==v[3].Number and v[3].Number==v[4].Number)
        return {v[2].Number,v[3].Number,v[4].Number,v[0].Number,v[1].Number};
    return {};
}
vector<int> LiangDui(vector<card>v){
    if(v[0].Number==v[1].Number and v[2].Number==v[3].Number)
        return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
    if(v[0].Number==v[1].Number and v[3].Number==v[4].Number)
        return {v[0].Number,v[1].Number,v[3].Number,v[4].Number,v[2].Number};
    if(v[1].Number==v[2].Number and v[3].Number==v[4].Number)
        return {v[1].Number,v[2].Number,v[3].Number,v[4].Number,v[0].Number};
    return {};
}
vector<int> DuiZi(vector<card>v){
    if(v[0].Number==v[1].Number)
        return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
    if(v[1].Number==v[2].Number)
        return {v[1].Number,v[2].Number,v[0].Number,v[3].Number,v[4].Number};
    if(v[2].Number==v[3].Number)
        return {v[2].Number,v[3].Number,v[0].Number,v[1].Number,v[4].Number};
    if(v[3].Number==v[4].Number)
        return {v[3].Number,v[4].Number,v[0].Number,v[1].Number,v[2].Number};
    return {};
}
vector<int> SanPai(vector<card>v){
    return {v[0].Number,v[1].Number,v[2].Number,v[3].Number,v[4].Number};
}
shoupai PanDing(vector<card>v){
    sort(v.begin(),v.end(),cmp);
    if(TongHua(v).size() and Shun(v).size()){
        vector<int>rt=Shun(v);
        if(rt[0]==14 and rt[1]==13)return {9,rt};
        else return {8,rt};
    }
    vector<int>rt;
    rt=SiTiao(v);
    if(rt.size())return {7,rt};
    rt=HuLu(v);
    if(rt.size())return {6,rt};
    rt=TongHua(v);
    if(rt.size())return {5,rt};
    rt=Shun(v);
    if(rt.size())return {4,rt};
    rt=SanTiao(v);
    if(rt.size())return {3,rt};
    rt=LiangDui(v);
    if(rt.size())return {2,rt};
    rt=DuiZi(v);
    if(rt.size())return {1,rt};
    rt=SanPai(v);
    return {0,rt};
}