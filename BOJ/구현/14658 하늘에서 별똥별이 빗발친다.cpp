#include<bits/stdc++.h>

using namespace std;


int main() {
    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);

    int res = 0;
    int n, m, l, k; cin >> n >> m >> l >> k;
    vector<pair<int, int>> pv;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        pv.push_back({a, b});
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            int x = pv[i].first, y = pv[j].second;
            int xx = x + l, yy = y + l;

            int cnt = 0;
            
                for(int d = 0; d < k; d++) {
                    auto tp = pv[d];
                    if(tp.first >= x && tp.first <= xx && tp.second >= y && tp.second <= yy) {
                        cnt++;
                    }
                }
            

            res = max(res, cnt);
        }
    }

    cout << k - res;

    return 0;
}
