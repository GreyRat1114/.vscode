#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<LL>> a(n + 2, vector<LL>(m + 2));
    vector<vector<LL>> d(n + 2, vector<LL>(m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    auto add = [&](int x1, int y1, int x2, int y2, LL c) {
        d[x1][y1] += c;
        d[x2 + 1][y1] -= c;
        d[x1][y2 + 1] -= c;
        d[x2 + 1][y2 + 1] += c;
    };

    while (q--) {
        int x1, y1, x2, y2;
        LL c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;

        add(x1, y1, x2, y2, c);
    }

    // 对差分数组求二维前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i - 1][j]
                     + d[i][j - 1]
                     - d[i - 1][j - 1];

            a[i][j] += d[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " \n"[j == m];
        }
    }

    return 0;
}