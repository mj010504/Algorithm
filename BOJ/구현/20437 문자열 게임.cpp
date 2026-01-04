#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        string w; int k;
        cin >> w >> k;

        vector<vector<int>> v(26);
        for(int j = 0; j < w.size(); j++) {
            auto c = w[j];
            v[c - 'a'].push_back(j);
        }

        int minn = INT_MAX;
        int maxx = -1;
        for(int j = 0; j < 26; j++) {
            auto tv = v[j];
            if(tv.size() >= k) {
                
                for(int l = 0; l <= tv.size() - k ; l++) {
                    minn = min(minn, tv[l + k - 1] - tv[l] + 1);
                    maxx = max(maxx, tv[l + k - 1] - tv[l] + 1);
                }
            }
        }

        if(maxx == -1) cout << -1 << '\n';
        else cout << minn << " " << maxx << '\n';
    }

    return 0;
}
