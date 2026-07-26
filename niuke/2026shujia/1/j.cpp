#include<bits/stdc++.h>
using namespace std;
using LL=long long;
set<string> st;
map<char,LL> mp;
void init(){
    vector<string> a1={"2","3","4","5","6","7","8","9","T","J","Q","K","A"};
    vector<string> b1={"C","D","H","S"};
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            string s=a1[i]+b1[j];
            st.insert(s);
            //cout<<s<<'\n';
        }
    }
    for(int i=0;i<13;i++){
        mp[a1[i][0]]=i;
    }
}
bool cmp(string s1,string s2){
    return mp[s1[0]]>mp[s2[0]];
}
bool Highcard(vector<string> &s){
    vector<string> a=s;
    sort(a.begin(),a.end(),cmp);
    LL tag=1;
    for(int i=1;i<5;i++){
        if(mp[a[i][0]]>=mp[a[i-1][0]])tag=0;
    }
    return tag==1?1:0;
}
bool Pair(vector<string> &s,vector<LL> &vec){
    vector<string> a=s;
    sort(a.begin(),a.end(),cmp);
    map<char,LL> cnt;
    for(int i=0;i<5;i++){
        cnt[s[i][0]]++;
    }
    LL tot3=0,tot2=0;
    LL val;
    for(auto x:cnt){
        if(x.second==2){tot2++;val=mp[x.first];};
    }    
    for(auto x:cnt){
        if(x.second==3)tot3++;
    }
    if(tot2==1&&tot3==0){
        vec[0]=val;
        vec[1]=val;
        LL c=0;
        for(int i=0;i<5;i++){
            if(mp[a[i][0]]==val)continue;
            vec[c++]=mp[a[i][0]];
        }
        return 1;
    }else{
        return 0;
    }
}
bool Twopairs(vector<string> &s){
    map<char,LL> cnt;
    for(int i=0;i<5;i++){
        cnt[s[i][0]]++;
    }
    LL tot3=0,tot2=0;
    for(auto x:cnt){
        if(x.second==2)tot2++;
    }    
    for(auto x:cnt){
        if(x.second==3)tot3++;
    }
    if(tot2==2&&tot3==0){
        return 1;
    }else{
        return 0;
    }
}
bool Threeofakind(vector<string> &s){
    map<char,LL> cnt;
    for(int i=0;i<5;i++){
        cnt[s[i][0]]++;
    }
    LL tot3=0,tot2=0;
    for(auto x:cnt){
        if(x.second==2)tot2++;
    }    
    for(auto x:cnt){
        if(x.second==3)tot3++;
    }
    if(tot3==1&&tot2==0){
        return 1;
    }else{
        return 0;
    }
}
bool Straight(vector<string> &s){
    vector<string> a=s;
    set<char> vis={'A','2','3','4','5'};
    LL tagv=1;
    set<char> v;
    for(int i=0;i<5;i++){
        v.insert(a[i][0]);
    }
    if(v==vis)return 1;
    sort(a.begin(),a.end(),cmp);
    LL tag=1;
    for(int i=1;i<5;i++){
        if(mp[a[i][0]]!=mp[a[i-1][0]]-1)tag=0;
    }
    return tag==1?1:0;    
}
bool Flush(vector<string> &s){
    LL tag=1;
    for(int i=1;i<5;i++){
        if(s[i][1]!=s[i-1][1])tag=0;
    }
    return tag==1?1:0;
}
bool Fullhouse(vector<string> &s){
    map<char,LL> cnt;
    for(int i=0;i<5;i++){
        cnt[s[i][0]]++;
    }
    LL tot3=0,tot2=0;
    for(auto x:cnt){
        if(x.second==2)tot2++;
        if(x.second==3)tot3++;
    }    
    if(tot3==1&&tot2==1){
        return 1;
    }else{
        return 0;
    }
}
bool Fourofakind(vector<string> &s){
    map<char,LL> cnt;
    for(int i=0;i<5;i++){
        cnt[s[i][0]]++;
    }
    LL tot4=0;
    for(auto x:cnt){
        if(x.second==4)tot4++;

    }    
    if(tot4==1){
        return 1;
    }else{
        return 0;
    }
}
bool Straightflush(vector<string> &s){
    if(!Straight(s))return 0;
    LL tag=1;
    for(int i=1;i<5;i++){
        if(s[i][1]!=s[i-1][1])tag=0;
    }
    return tag==1?1:0;
}
bool Royalflush(vector<string> &s){
    if(Flush(s)==0)return 0;
    vector<string> a=s;
    sort(a.begin(),a.end(),cmp);   
    vector<char> check={'A','K','Q','J','T'};
    LL tag=1;
    for(int i=0;i<5;i++){
        if(a[i][0]!=check[i])tag=0;
    }
    return tag==1?1:0;
}
// LL pipei(LL x,vector<string> &s){
//     if(x==1){
//         return Highcard(s);
//     }else if(x==2){
//         return Pair(s);
//     }else if(x==3){
//         return Twopairs(s);
//     }else if(x==4){
//         return Threeofakind(s);
//     }else if(x==5){
//         return Straight(s);
//     }else if(x==6){
//         return Flush(s);
//     }else if(x==7){
//         return Fullhouse(s);
//     }else if(x==8){
//         return Fourofakind(s);
//     }else if(x==9){
//         return Straightflush(s);
//     }else{
//         return Royalflush(s);
//     }
// }
LL comp(LL n,vector<string> &p1,vector<string> &p2){
    vector<string> a=p1,b=p2;
    if(n==1){
        sort(a.begin(),a.end(),cmp);
        sort(a.begin(),a.end(),cmp);
        LL tag=0;
        for(int i=0;i<5;i++){
            if(mp[a[i][0]]>mp[b[i][0]]){
                tag=1;
                break;
            }else if(mp[a[i][0]]<mp[b[i][0]]){
                tag=-1;
                break;
            }
        }
        return tag;        
    }else if(n==2){
        map<string,LL> cnt1,cnt2;
        for(int i=0;i<5;i++){

        }
    }else if(n==3){
        
    }else if(n==4){
        
    }else if(n==5){
        
    }else if(n==6){
        
    }else if(n==7){
        
    }else if(n==8){
        
    }else if(n==9){
        
    }else if(n==10){
        
    }
}
void solve(){
    string s;
    set<string> st1,st2,sts;
    
    vector<string> p1,p2;
    for(int i=1;i<=4;i++){
        cin>>s;
        p1.push_back(s);
        //cout<<p1.back()<<'\n';
        st1.insert(s);
        sts.insert(s);
    } 
    for(int i=1;i<=4;i++){
        cin>>s;
        p2.push_back(s);
        //cout<<p2.back()<<'\n';
        st2.insert(s);
        sts.insert(s);
    }
    // for(auto x:p1){
    //     cout<<x<<'\n';
    // }
    LL max2=0,maxx1=0,maxi1=0;
    string xx1,xi1,x2;
    
    auto check=[&](vector<string> &p,string x,string y)->LL{
        vector<string> a=p,b=p;
        a.push_back(x);
        b.push_back(y);
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end(),cmp);
        LL tag=0;
        for(int i=0;i<5;i++){
            if(mp[a[i][0]]>mp[b[i][0]]){
                tag=-1;
                break;
            }else if(mp[a[i][0]]<mp[b[i][0]]){
                tag=1;
                break;                
            }
        }
        return tag;
    };    
    for(auto x:st){
        if(sts.count(x))continue;
        for(int i=10;i>=1;i--){
            p2.push_back(x);
            LL h=pipei(i,p2);
            p2.pop_back();
            if(h==1){
                if(i>max2){
                    max2=i;
                    x2=x;
                }else if(i==max2){
                    LL ans=check(p2,x2,x);
                    if(ans==1)x2=x;
                }
                break;
            }
        }
    }
    for(auto x:st){
        if(sts.count(x))continue;
        for(int i=10;i>=1;i--){
            p1.push_back(x);
            LL h=pipei(i,p1);
            p1.pop_back();
            if(h==1){
                if(i>=maxx1){
                    if(i>maxx1){
                        maxi1=maxx1;
                        xi1=xx1;
                        maxx1=i;
                        xx1=x;
                    }else{
                        LL ans=check(p1,xx1,x);
                        if(ans==1){
                            maxi1=maxx1;
                            xi1=xx1;                            
                            xx1=x;
                        }

                    }
                }else if(i>=maxi1){
                    if(i>maxi1){
                        maxi1=i;
                        xi1=x;                        
                    }else{
                        LL ans=check(p1,xi1,x);
                        if(ans==1){
                            xi1=x;
                        }
                    }                    

                }
                break;
            }
        }
    }    
    LL maxn=0;
    for(int i=1;i<=10;i++){
        p2.push_back(xx1);
        LL can=pipei(i,p2);
        if(can==1){
            maxn=i;
        }
        p2.pop_back();
    }
    LL tag1=0,tag2=0,tag0=0;
    auto cp=[&](vector<string> &p1,vector<string> &p2)->LL{
        vector<string> a=p1,b=p2;
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end(),cmp);
        LL tag=0;
        for(int i=0;i<5;i++){
            if(mp[a[i][0]]>mp[b[i][0]]){
                tag=1;
                break;
            }else if(mp[a[i][0]]<mp[b[i][0]]){
                tag=-1;
                break;
            }
        }
        return tag;
    };
    if(x2==xx1&&max2>=maxi1){
        if(max2>maxi1){
            tag2=1;
        }else if(max2==maxi1){
            p2.push_back(xx1);
            p1.push_back(xi1);
            if(cp(p1,p2)==-1){
                tag2=1;
            }
            p2.pop_back();
            p1.pop_back();  
        }        
    }else if(x2!=xx1){
        if(max2>maxx1){
            tag2=1;
        }else if(max2==maxx1){
            p2.push_back(x2);
            p1.push_back(xx1);            
            if(cp(p1,p2)==-1){
                tag2=1;
            }
            p2.pop_back();
            p1.pop_back();
        }
        if(maxn>maxi1){
            tag2=1;
        }else if(maxn==maxi1){
            p2.push_back(xx1);
            p1.push_back(xi1);
            if(cp(p1,p2)==-1){
                tag2=1;
            }
            p2.pop_back();
            p1.pop_back();            
        }
    }
    if(tag2){
        cout<<"GeiWoCaPiXie"<<'\n';
        return;
    }
    if(maxx1>max2){
        tag1=1;
    }else if(maxx1==max2){
        p2.push_back(x2);
        p1.push_back(xx1);            
        if(cp(p1,p2)==1){
            tag1=1;
        }
        p2.pop_back();
        p1.pop_back();        
    }
    if(maxi1>maxn){
        tag0=1;
    }else if(maxi1==maxn){
        p2.push_back(xx1);
        p1.push_back(xi1);
        if(cp(p1,p2)==1){
            tag0=1;
        }
        p2.pop_back();
        p1.pop_back();  
    }
    if(tag0&&tag1){
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