#include<bits/stdc++.h>

using namespace std;

int change(int t) {
    if(t == 0) return 1;
    return 0;
}


int res = INT_MAX;

void solve(bool first, vector<int> v, vector<int> target) {
    int cnt = 0;
    if(first) {
        cnt++;
        v[0] = change(v[0]);
        v[1] = change(v[1]);
    }

    for(int i = 1; i < v.size(); i++) {
        if(v[i - 1] != target[i - 1]) {
            // push
            v[i - 1] = change(v[i - 1]);
            v[i] = change(v[i]);
            if(i + 1 < v.size()) v[i + 1] = change(v[i + 1]);
            cnt++;
        }
    }

     if(v[v.size() - 1] == target[v.size() - 1]) res = min(res, cnt);
}

int main() {
   // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cur(n), next(n);
    string str1, str2; cin >> str1 >> str2;
    for(int i = 0; i < n; i++) {
        cur[i] = str1[i] - '0';
    }

    for(int i = 0; i < n; i++) {
        next[i] = str2[i] - '0';
    }

    solve(true, cur, next);
    solve(false, cur, next);


    if(res == INT_MAX) cout << - 1;
    else cout << res;

    return 0;
}
