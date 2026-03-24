#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
unordered_map<int, int>ump;
int u[N];
int f(int x) {
	if (x == 0) return 0;
	if (ump.count(x)) return ump[x];
	int res = 1;
	while (x) {
		res *= x % 10;
		x /= 10;
	}
	u[x] = res;
	return res;
}

int g(int x) {
	int res = 0;
	while (x != f(x)) x = f(x), ++res;
	return res;
}
int sum, mx;
int cnt[10]; // 每种数字的数量
vector<int>ans;

int build() { // 根据 cnt[] 构建数字
	int num = 0;
	for (int i = 9; i >= 0; --i)
		for (int j = 0; j < cnt[i]; ++j)
			num *= 10, num += i;
	return num;
}

void dfs(int type) {
	if (type == 10) { // 已经遍历完0~9
		int num = build();
		int res = g(num);
		if (res > mx)
			mx = res, ans.clear();
		if (res == mx)
			ans.push_back(num);
		return;
	}

	for (int i = 0; i + sum < 18; ++i) {
		cnt[type] = i;

		sum += i;
		dfs(type + 1);
		sum -= i;
	}
}

void solve() {
	dfs(0);
	cout << mx << endl;
	for (auto&x : ans)cout << x << endl;
}
int main(){
    solve();
    return 0;
}