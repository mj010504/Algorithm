#include<bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) parent[x] = y;   
}

int main() {
    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    vector<int> cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    for(int i = 0; i < n; i++) {
        parent.push_back(i);
    }


    vector<vector<int>> rv(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        unite(a, b);
    }

    vector<bool> friends(n, false);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(friends[i] == false) {
            int minCost = cost[i];
            friends[i] = true;
            int temp = find(i);
             for(int j = i + 1; j < n; j++) {
                if(find(j) == temp) {
                    friends[j] = true;
                    minCost = min(minCost, cost[j]);
                }
            }

            res += minCost;
            if(res > k) break;
        }
    }
    
    if(res > k) cout << "Oh no";
    else cout << res;

}
