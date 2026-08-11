#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct BigInt {
    static const int base = 1000000000;
    static const int base_digits = 9;

    vector<int> a; // 小端存储
    int sign = 1;

    BigInt(long long v = 0) {
        *this = v;
    }

    BigInt(const string& s) {
        read(s);
    }

    // long long -> BigInt
    BigInt& operator=(long long v) {
        sign = 1;
        a.clear();

        unsigned long long x;

        // 这样写可以处理 LLONG_MIN
        if (v < 0) {
            sign = -1;
            x = 0ULL - (unsigned long long)v;
        } else {
            x = (unsigned long long)v;
        }

        while (x) {
            a.push_back(x % base);
            x /= base;
        }

        return *this;
    }

    // string -> BigInt
    BigInt& read(const string& s) {
        sign = 1;
        a.clear();

        int pos = 0;

        if (s[pos] == '-' || s[pos] == '+') {
            if (s[pos] == '-') sign = -1;
            pos++;
        }

        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            int l = max(pos, i - base_digits + 1);

            for (int j = l; j <= i; j++) {
                x = x * 10 + s[j] - '0';
            }

            a.push_back(x);
        }

        trim();

        return *this;
    }

    // 去前导 0
    void trim() {
        while (!a.empty() && a.back() == 0) {
            a.pop_back();
        }

        if (a.empty()) {
            sign = 1;
        }
    }

    bool isZero() const {
        return a.empty();
    }

    BigInt abs() const {
        BigInt res = *this;
        res.sign = 1;
        return res;
    }

    // 比较绝对值
    // x < y : -1
    // x = y : 0
    // x > y : 1
    static int absCmp(const BigInt& x, const BigInt& y) {
        if (x.a.size() != y.a.size()) {
            return x.a.size() < y.a.size() ? -1 : 1;
        }

        for (int i = (int)x.a.size() - 1; i >= 0; i--) {
            if (x.a[i] != y.a[i]) {
                return x.a[i] < y.a[i] ? -1 : 1;
            }
        }

        return 0;
    }

    // ================= 比较 =================

    friend bool operator < (const BigInt& x, const BigInt& y) {
        if (x.sign != y.sign) {
            return x.sign < y.sign;
        }

        int c = absCmp(x, y);

        if (x.sign == 1) {
            return c < 0;
        } else {
            return c > 0;
        }
    }

    friend bool operator > (const BigInt& x, const BigInt& y) {
        return y < x;
    }

    friend bool operator <= (const BigInt& x, const BigInt& y) {
        return !(y < x);
    }

    friend bool operator >= (const BigInt& x, const BigInt& y) {
        return !(x < y);
    }

    friend bool operator == (const BigInt& x, const BigInt& y) {
        return x.sign == y.sign && x.a == y.a;
    }

    friend bool operator != (const BigInt& x, const BigInt& y) {
        return !(x == y);
    }

    // ================= 负号 =================

    BigInt operator - () const {
        BigInt res = *this;

        if (!res.isZero()) {
            res.sign = -res.sign;
        }

        return res;
    }

    // ================= 加减 =================

    BigInt& operator += (const BigInt& v) {
        if (sign == v.sign) {

            int carry = 0;

            for (size_t i = 0;
                 i < max(a.size(), v.a.size()) || carry;
                 i++) {

                if (i == a.size()) {
                    a.push_back(0);
                }

                long long cur =
                    (long long)a[i]
                    + carry
                    + (i < v.a.size() ? v.a[i] : 0);

                carry = cur >= base;

                if (carry) {
                    cur -= base;
                }

                a[i] = cur;
            }

        } else {

            if (absCmp(*this, v) >= 0) {

                int carry = 0;

                for (size_t i = 0;
                     i < v.a.size() || carry;
                     i++) {

                    long long cur =
                        (long long)a[i]
                        - (i < v.a.size() ? v.a[i] : 0)
                        - carry;

                    carry = cur < 0;

                    if (carry) {
                        cur += base;
                    }

                    a[i] = cur;
                }

                trim();

            } else {

                BigInt t = v;
                t += *this;
                *this = t;
            }
        }

        return *this;
    }

    BigInt& operator -= (const BigInt& v) {
        return *this += (-v);
    }

    friend BigInt operator + (BigInt a, const BigInt& b) {
        return a += b;
    }

    friend BigInt operator - (BigInt a, const BigInt& b) {
        return a -= b;
    }

    // ================= BigInt * int =================

    BigInt& operator *= (int v) {
        if (v < 0) {
            sign = -sign;
            v = -v;
        }

        if (v == 0 || isZero()) {
            a.clear();
            sign = 1;
            return *this;
        }

        long long carry = 0;

        for (size_t i = 0; i < a.size() || carry; i++) {

            if (i == a.size()) {
                a.push_back(0);
            }

            long long cur =
                carry + 1LL * a[i] * v;

            a[i] = cur % base;
            carry = cur / base;
        }

        trim();

        return *this;
    }

    friend BigInt operator * (BigInt a, int v) {
        return a *= v;
    }

    friend BigInt operator * (int v, BigInt a) {
        return a *= v;
    }

    // ================= BigInt * BigInt =================
    // 朴素 O(nm)

    BigInt& operator *= (const BigInt& v) {
        if (isZero() || v.isZero()) {
            a.clear();
            sign = 1;
            return *this;
        }

        vector<long long> res(
            a.size() + v.a.size(),
            0
        );

        for (size_t i = 0; i < a.size(); i++) {

            long long carry = 0;

            for (size_t j = 0;
                 j < v.a.size() || carry;
                 j++) {

                long long cur =
                    res[i + j]
                    + carry
                    + (j < v.a.size()
                       ? 1LL * a[i] * v.a[j]
                       : 0);

                res[i + j] = cur % base;
                carry = cur / base;
            }
        }

        a.resize(res.size());

        for (size_t i = 0; i < res.size(); i++) {
            a[i] = res[i];
        }

        sign *= v.sign;

        trim();

        return *this;
    }

    friend BigInt operator * (BigInt a, const BigInt& b) {
        return a *= b;
    }

    // ================= BigInt / int =================

    BigInt& operator /= (int v) {
        if (v == 0) {
            throw runtime_error("division by zero");
        }

        if (v < 0) {
            sign = -sign;
            v = -v;
        }

        long long rem = 0;

        for (int i = (int)a.size() - 1; i >= 0; i--) {

            long long cur =
                a[i] + rem * base;

            a[i] = cur / v;
            rem = cur % v;
        }

        trim();

        return *this;
    }

    friend BigInt operator / (BigInt a, int v) {
        return a /= v;
    }

    // BigInt % int
    int operator % (int v) const {
        if (v == 0) {
            throw runtime_error("mod by zero");
        }

        int vv = v < 0 ? -v : v;

        long long m = 0;

        for (int i = (int)a.size() - 1; i >= 0; i--) {
            m = (a[i] + m * base) % vv;
        }

        return sign * m;
    }

    // ================= BigInt / BigInt =================

    static pair<BigInt, BigInt> divmod(
        const BigInt& a1,
        const BigInt& b1
    ) {
        if (b1.isZero()) {
            throw runtime_error("division by zero");
        }

        int norm =
            base / ((long long)b1.a.back() + 1);

        BigInt a = a1.abs() * norm;
        BigInt b = b1.abs() * norm;

        BigInt q, r;

        q.a.assign(a.a.size(), 0);

        for (int i = (int)a.a.size() - 1; i >= 0; i--) {

            // r = r * base + a[i]
            r.a.insert(r.a.begin(), a.a[i]);
            r.trim();

            long long s1 =
                r.a.size() <= b.a.size()
                ? 0
                : r.a[b.a.size()];

            long long s2 =
                r.a.size() <= b.a.size() - 1
                ? 0
                : r.a[b.a.size() - 1];

            long long d =
                ((long long)base * s1 + s2)
                / b.a.back();

            if (d >= base) {
                d = base - 1;
            }

            r -= b * (int)d;

            while (r.sign == -1) {
                r += b;
                d--;
            }

            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;

        q.trim();
        r.trim();

        r /= norm;

        return {q, r};
    }

    BigInt& operator /= (const BigInt& v) {
        return *this = divmod(*this, v).first;
    }

    BigInt& operator %= (const BigInt& v) {
        return *this = divmod(*this, v).second;
    }

    friend BigInt operator / (
        const BigInt& a,
        const BigInt& b
    ) {
        return divmod(a, b).first;
    }

    friend BigInt operator % (
        const BigInt& a,
        const BigInt& b
    ) {
        return divmod(a, b).second;
    }

    // ================= 输入输出 =================

    friend istream& operator >> (
        istream& in,
        BigInt& v
    ) {
        string s;
        in >> s;
        v.read(s);
        return in;
    }

    friend ostream& operator << (
        ostream& out,
        const BigInt& v
    ) {
        if (v.sign == -1 && !v.isZero()) {
            out << '-';
        }

        if (v.a.empty()) {
            return out << 0;
        }

        out << v.a.back();

        for (int i = (int)v.a.size() - 2; i >= 0; i--) {
            out << setw(base_digits)
                << setfill('0')
                << v.a[i];
        }

        return out;
    }
};
void solve(){
    BigInt n;
    cin>>n;
    BigInt ans=1;
    while(n!=1){
        n=n/2;
        ans=ans*2;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}