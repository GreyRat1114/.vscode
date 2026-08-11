// void print(__int128 x) {
//     if (x < 0) {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9) print(x / 10);
//     putchar(x % 10 + '0');
// }
// LL read() {
//     LL x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar();a
//     }
//     while (ch >= '0' && ch <= '9') {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }
//     return x * f;
// }

// 关流
// using i128=__int128_t;
// using u128=__uint128_t;
// ostream& operator<<(ostream& out,i128 x){
//     if(x<0)out<<'-';
//     u128 y=x<0?-(u128)x:(u128)x;
//     if(!y)return out<<0;
//     string s;
//     while(y)s+=char('0'+y%10),y/=10;
//     reverse(s.begin(),s.end());
//     return out<<s;
// }
// istream& operator>>(istream& in,i128& x){
//     string s;in>>s;
//     x=0;
//     int p=0,tag=1;
//     if(s[0]=='-')tag=-1,p=1;
//     for(;p<s.size();p++)x=x*10+s[p]-'0';
//     x*=tag;
//     return in;
// }