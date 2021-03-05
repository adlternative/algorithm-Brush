
#include <bits/stdc++.h>

using namespace std;
int n, t, m, x;
int temp_nation[1000005];
int ans;

struct node {
    int s, t;

    bool operator<(const node &rhs) const {
        return this->t > rhs.t;
    }
};

int main() {
    priority_queue<node/*, vector<node>*//*, greater<int>*/> ship;
    node h;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t >> m;
        while (!ship.empty()) {
            h = ship.top();
            if (h.t + 86400 <= t) {
                temp_nation[h.s]--;
                if (temp_nation[h.s] == 0)
                    ans--;
                ship.pop();
                continue;
            }
            break;
        }
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            h.s = x, h.t = t;
            ship.push(h);
            temp_nation[x]++;
            if (temp_nation[x] == 1) ans++;
        }
        cout << ans << endl;//模拟完了以后就输出答案
    }
    return 0;
}