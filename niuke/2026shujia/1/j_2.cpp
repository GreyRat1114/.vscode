#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define shoupai pair<int,vector<int> >
vector<string> a1={"2","3","4","5","6","7","8","9","T","J","Q","K","A"};
vector<string> b1={"C","D","H","S"};
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
    bool operator<(const card& other) const {
        if (Number != other.Number) {
            return Number > other.Number; // 点数从大到小
        }

        return Color < other.Color; // 点数相同时按花色排序
    }
};
set<card> st;
void init(){
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            string s=a1[i]+b1[j];
            card cd;
            cd.init(s);
            st.insert(cd);
        }
    }
}
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
LL MAX(shoupai x,shoupai y){
    if(x.first!=y.first){
        if(x.first>y.first)return 1;
        return 0;
    }
    for(int i=0;i<5;++i){
        if(x.second[i]!=y.second[i]){
            if(x.second[i]>y.second[i])return 1;
            return 0;
        }
    }
    return 0;
}

void solve(){
    vector<card> cs(15),rem;
    vector<card> p1,p2;
    set<card> st1,st2;
    vector<string> S(20);
    for(int i=1;i<=4;i++){
        cin>>S[i];
        cs[i].init(S[i]);
        p1.push_back(cs[i]);
        st1.insert(cs[i]);
    }
    for(int i=5;i<=8;i++){
        cin>>S[i];
        cs[i].init(S[i]);
        p2.push_back(cs[i]);
        st2.insert(cs[i]);
    }
    LL hasx2=0,hasxi1=0,hasxx1=0;
    shoupai xi1,xx1,x2,x21;
    card maxcd;
    for(auto x:st){
        if(st1.count(x)|st2.count(x))continue;
        p2.push_back(x);
        shoupai cur=PanDing(p2);
        p2.pop_back();
        if(!hasx2||MAX(cur,x2)){
            hasx2=1;
            x2=cur;
        }
    }
    for(auto x:st){
        if(st1.count(x)|st2.count(x))continue;
        p1.push_back(x);
        shoupai cur=PanDing(p1);
        p1.pop_back();
        if(!hasxx1||MAX(cur,xx1)){
            hasxx1=1;
            xi1=xx1;
            xx1=cur;
            maxcd=x;
        }else if(!hasxi1||MAX(cur,xi1)){
            hasxi1=1;
            xi1=cur;
        }
    }   
    p2.push_back(maxcd);
    x21=PanDing(p2);
    p2.pop_back();
    if(MAX(x2,xx1)||MAX(x21,xi1)){
        cout<<"GeiWoCaPiXie"<<'\n';
        return;
    }
    if(MAX(xx1,x2)&&MAX(xi1,x21)){
        cout<<"WoYaoYanPai"<<'\n';
        return;
    }
    cout<<"PaiMeiYouWenTi"<<'\n';
    
}
int main(){
    init();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}