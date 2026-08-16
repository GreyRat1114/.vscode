#include<bits/stdc++.h>
using namespace std;
using LL=long long;

namespace IO{
    const int S=1<<20;
    char ib[S],ob[S];int ip,il,op;
    inline int gc(){
        if(ip==il)il=fread(ib,1,S,stdin),ip=0;
        return il?ib[ip++]:EOF;
    }
    inline void pc(char c){
        if(op==S)fwrite(ob,1,op,stdout),op=0;
        ob[op++]=c;
    }
    template<class T>
    inline void read(T&x){
        x=0;int c=gc(),f=1;
        while(c!=EOF&&(c<'0'||c>'9'))f=c=='-'?-1:f,c=gc();
        while(c>='0'&&c<='9')x=x*10+c-'0',c=gc();
        if(f<0)x=-x;
    }
    inline void read(string&s){
        s.clear();int c=gc();
        while(c!=EOF&&c<=' ')c=gc();
        while(c!=EOF&&c>' ')s+=c,c=gc();
    }
    inline void read(char&c){
        int x=gc();
        while(x!=EOF&&x<=' ')x=gc();
        c=x;
    }
    template<class T,class...A>
    inline void read(T&x,A&...a){read(x);read(a...);}
    template<class T>
    inline void write(T x,char c='\n'){
        if(x<0)pc('-'),x=-x;
        if(!x)pc('0');
        else{
            char s[50];int n=0;
            while(x)s[n++]=x%10+'0',x/=10;
            while(n)pc(s[--n]);
        }
        if(c)pc(c);
    }
    inline void write(const string&s,char c='\n'){
        for(char x:s)pc(x);
        if(c)pc(c);
    }
    inline void write(const char*s,char c='\n'){
        while(*s)pc(*s++);
        if(c)pc(c);
    }
    inline void write(char x,char c='\n'){
        pc(x);if(c)pc(c);
    }
    struct F{~F(){fwrite(ob,1,op,stdout);}}f;
}
using IO::read;
using IO::write;