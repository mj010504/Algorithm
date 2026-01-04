#include<bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    stack<int> s;
    vector<int> left(n, 0), right(n, 0);
    vector<int> near(n, -1);

    for(int i = 0; i < n; i++) {
        int temp = v[i];
        while(!s.empty() && v[s.top()] <= temp) {
            s.pop();
        }

        left[i] = s.size();
        if(!s.empty()) near[i] = s.top();
        s.push(i);
    }

    while(!s.empty()) {
        s.pop();
    }

    for(int i = n - 1; i >= 0; i--) {
        int temp = v[i];
        while(!s.empty() && v[s.top()] <= temp) {
            s.pop();
        }

        right[i] = s.size();
        if(!s.empty()) {
            if(near[i] == -1) near[i] = s.top();
            else if(abs(near[i] - i) > abs(i - s.top())) near[i] = s.top();
        }
        s.push(i);
    }  


    int res = 0;
    for(int i = 0; i < n; i++) {
        int sum = left[i] + right[i];
        if(sum == 0) cout << 0 << '\n';
        else {
            cout << sum << " " << near[i] + 1 << '\n';
        }
    }

    return 0;
}
