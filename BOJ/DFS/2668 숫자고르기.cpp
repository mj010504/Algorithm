#include<bits/stdc++.h>

using namespace std;


vector<int> res;
vector<int> v;

vector<int> dfs(int start, vector<bool> visited) {
    vector<int> tv;
    tv.push_back(start);
    int cur = start;
    while(1) {
        if(v[cur] == start) {
            return tv;
        }
        else {
            if(!visited[v[cur]]) {
                visited[v[cur]] = true;
                tv.push_back(v[cur]);
                cur = v[cur];
            }
            else {
                vector<int> empty;
                return empty;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    v.resize(n + 1);
    vector<bool> visited(n, false);

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(i == v[i]) {
            visited[i] = true;
            res.push_back(i);
        }
    }

    int maxx = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && !visited[v[i]]) {
            auto tv = dfs(i, visited);
            for(auto t : tv) {
                res.push_back(t);
                visited[t] = true;
            }
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(auto r : res) cout << r << '\n';

    return 0;
}
