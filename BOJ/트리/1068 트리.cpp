#include<bits/stdc++.h>

using namespace std;

struct node {
    vector<int> child;
};

int main() {
    freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n;
    vector<node> nv(n);
    int root;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == -1) root = i;
        else {
            nv[a].child.push_back(i);
        }
    }

    int del; cin >> del;

    int res = 0;
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        auto temp = q.front(); q.pop();
        if(temp == del) continue;

        auto child = nv[temp].child;

        if(child.empty()) {
            res++;
        }
        else if(child.size() == 1 && child[0] == del) res++;
        else {
            for(auto c : nv[temp].child) {
                if(c != del)q.push(c);
            }
        }
    }

    cout << res;
}
